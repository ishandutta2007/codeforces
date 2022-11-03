{-# LANGUAGE FlexibleInstances #-}

import Data.Array.Unboxed
import Data.Maybe
import Data.Int
import qualified Data.ByteString.Char8 as BS

type Vec = (UArray Int Int, UArray Int Int64, UArray Int Int64)

instance Num Vec where
    (a1, b1, c1) * (a2, b2, c2) = (listArray x [a1 ! (a2 ! i) | i <- [0 .. n']], listArray x [(b1 ! (a2 ! i)) + (b2 ! i) | i <- [0 .. n']], listArray x [min (c1 ! (a2 ! i)) (c2 ! i) | i <- [0 .. n']])
        where
            x@(_, n') = bounds a1
            

readInts :: Integral a => IO [a]
readInts = (map (fromIntegral . fst . fromJust . BS.readInt) . BS.words) `fmap` BS.getLine

main = do
    [n, k] <- (map read . words) `fmap` getLine :: IO [Int64]
    fs <- readInts
    ws <- readInts
    let (_, b, c) = ((listArray x fs, listArray x ws, listArray x ws) :: Vec) ^ k
        x = (0, fromIntegral $ n - 1 :: Int)
    mapM_ putStrLn [show y ++ " " ++ show z | (y, z) <- zip (elems b) (elems c)]