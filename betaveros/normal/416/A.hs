-- @betaveros :: vim:set fdm=marker:
{-# LANGUAGE LambdaCase, NPlusKPatterns, TupleSections, BangPatterns, ScopedTypeVariables #-}
{-# OPTIONS_GHC -fno-warn-unused-imports -fno-warn-missing-signatures #-}
-- import ALL the things! {{{
-- hiding clauses are to allow Data.Foldable's generalizations
import Prelude hiding (mapM, mapM_, sequence, sequence_, foldl, foldl1, foldr, foldr1, and, or, any, all, sum, product, concat, concatMap, maximum, minimum, elem, notElem)
import Control.Applicative
import Control.Arrow
import Control.Exception
import Control.Monad hiding (mapM, mapM_, forM, forM_, sequence, sequence_, msum)
import Control.Monad.ST

import qualified Data.ByteString.Char8 as BS
import Data.ByteString.Char8 (ByteString)
import Data.Bits
import Data.Char
import Data.Either
import Data.Foldable
import Data.Function
import Data.IORef
import Data.List hiding (foldl, foldl', foldl1, foldl1', foldr, foldr1, concat, concatMap, and, or, any, all, sum, product, maximum, minimum, elem, notElem, find)
import Data.Maybe
import Data.Monoid
import Data.Ord
import Data.STRef
import Data.String
import Data.Traversable
import Data.Tuple

import qualified Data.Map as Map
import Data.Map (Map)
import qualified Data.Set as Set
import Data.Set (Set)
import qualified Data.Sequence as Seq
import Data.Sequence (Seq, (<|), (|>), (><))

import Debug.Trace
import Text.Printf
import System.IO
-- }}}
-- silly utilities {{{
-- stolen from lens:
a & f = f a
a <&> f = fmap f a
infixl 1 &, <&>

fi :: (Integral a, Num b) => a -> b
fi = fromIntegral
glength :: (Num b) => [a] -> b
glength = genericLength

readInt     = read :: String -> Int
readInteger = read :: String -> Integer
-- (!?) :: (Ord k) => Map k v -> k -> Maybe v
-- (!?) = flip Map.lookup
histogram :: (Ord a, Num b) => [a] -> Map a b
histogram = Map.fromListWith (+) . map (,1)
-- }}}
-- input and output {{{
bsGetLine :: IO ByteString
bsGetLine = fst . BS.spanEnd isSpace <$> BS.getLine

inputInt     = (read <$> getLine) :: IO Int
inputInteger = (read <$> getLine) :: IO Integer
inputDouble  = (read <$> getLine) :: IO Double

inputRow :: (Read a) => IO [a]
inputRow = map read . words <$> getLine
inputInts     = inputRow :: IO [Int]
inputIntegers = inputRow :: IO [Integer]
inputDoubles  = inputRow :: IO [Double]

ssUnwords :: [ShowS] -> ShowS
ssUnwords [] = id
ssUnwords (x:xs) = x . (' ':) . ssUnwords xs

ssUnlines :: [ShowS] -> ShowS
ssUnlines [] = id
ssUnlines (x:xs) = x . ('\n':) . ssUnlines xs

showMany :: (Show a) => [a] -> String
showMany xs = ssUnwords (map shows xs) ""
showMatrix :: (Show a) => [[a]] -> String
showMatrix xs = ssUnlines (map (ssUnwords . map shows) xs) ""

printMany :: (Show a) => [a] -> IO ()
printMany xs = putStrLn (showMany xs)
printMatrix :: (Show a) => [[a]] -> IO ()
printMatrix xs = putStr (showMatrix xs)
-- }}}

data Answer = Lt !Int | Geq !Int

neg :: Answer -> Answer
neg (Lt a) = Geq a
neg (Geq a) = Lt a

inputAnswer :: IO Answer
inputAnswer = do
	[sign, ns, ts] <- words <$> getLine
	let n :: Int = read ns
	let t = ts == "Y"
	let ans = case sign of
		">=" -> Geq n
		"<" -> Lt n
		">" -> Geq (n + 1)
		"<=" -> Lt (n + 1)
	return $ if t then ans else neg ans


solve :: [Answer] -> Maybe Int
solve = go (-2^30, 2^30)
	where
		go (a,b) [] | a < b = Just a
		go (a,b) (Lt x : xs) = go (a, min b x) xs
		go (a,b) (Geq x : xs) = go (max a x, b) xs
		go _ _ = Nothing

main :: IO ()
main = do
	n <- inputInt
	a <- replicateM n inputAnswer
	case solve a of
		Just x -> print x
		Nothing -> putStrLn "Impossible"