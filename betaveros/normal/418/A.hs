-- @betaveros :: vim:set fdm=marker:
{-# LANGUAGE LambdaCase, NPlusKPatterns, TupleSections #-}
{-# OPTIONS_GHC -fno-warn-unused-imports -fno-warn-missing-signatures #-}
-- import ALL the things! {{{
import Control.Applicative
import Control.Arrow
import Control.Exception
import Control.Monad
import Control.Monad.ST

import Data.Bits
import Data.Char
import Data.Either
import Data.Function
import Data.IORef
import Data.List
import Data.Maybe
import Data.Monoid
import Data.Ord
import Data.STRef
import Data.String
import Data.Tuple

import qualified Data.Map as Map
import Data.Map (Map)
import qualified Data.Set as Set
import Data.Set (Set)
import qualified Data.Sequence as Seq
import Data.Sequence (Seq, (<|), (|>), (><))

import Debug.Trace
import Text.Printf
-- }}}
-- silly utilities {{{
(#) = flip ($)
infixl 0 #

glength :: (Num b) => [a] -> b
glength = genericLength

readInt     = read :: String -> Int
readInteger = read :: String -> Integer
-- (!?) :: (Ord k) => Map k v -> k -> Maybe v
-- (!?) = flip Map.lookup
histogram :: (Ord a, Num b) => [a] -> Map a b
histogram = Map.fromListWith (+) . map (,1)

(!>) :: Seq a -> Int -> a
(!>) = Seq.index
-- }}}
-- input and output {{{
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
printMany xs = putStrLn . unwords $ map show xs
printMatrix :: (Show a) => [[a]] -> IO ()
printMatrix xs = putStr . unlines $ map (unwords . map show) xs
-- }}}

main :: IO ()
main = do
	[n, k] <- inputInts
	if (2*k > n-1) then print (-1) else do
		print $ n*k
		printMatrix [[(i+1),((i+j+1)`rem`n + 1)] | i <- [0..n-1], j <- [0..k-1]]