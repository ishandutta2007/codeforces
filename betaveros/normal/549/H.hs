-- @betaveros :: vim:set fdm=marker:
{-# LANGUAGE LambdaCase, NPlusKPatterns, TupleSections #-}
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

test a b c d x = let
        ad = [a' * d' | a' <- [a - x, a + x], d' <- [d - x, d + x]]
        bc = [b' * c' | b' <- [b - x, b + x], c' <- [c - x, c + x]]
    in minimum ad < maximum bc && maximum ad > minimum bc

refine a b c d (lo, hi) = let
        mid = (lo + hi) / 2
    in
        if test a b c d mid then (lo, mid) else (mid, hi)

solve a b c d
    | a * d == b * c = 0.0
    | otherwise = snd $ iterate (refine a b c d) (0.0, 1.0e9) !! 1024

main :: IO ()
main = do
    [a, b] <- map fi <$> inputIntegers
    [c, d] <- map fi <$> inputIntegers
    print $ solve a b c d