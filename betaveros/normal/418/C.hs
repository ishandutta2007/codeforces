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
-- }}}

row :: Int -> [Int]
row 1 = [1]
row 2 = [3,4]
row 3 = [3,4,12]
row m = (m-2) : replicate (m-1) 2

table :: Int -> Int -> [[Int]]
table n m = [[x*y | y <- row m] | x <- row n]

main :: IO ()
main = do
	[n,m] <- inputInts
	let t = table n m in forM_ t $ \r -> putStrLn $ unwords (map show r)