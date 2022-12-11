import Data.Bits
import Data.List

bits :: Integral a => a -> [a]
bits n = bitsWithMul n 1
    where bitsWithMul 0 _ = []
          bitsWithMul n m
            | n `mod` 2 == 1    = m : bitsWithMul (n `div` 2) (m * 2)
            | otherwise         =     bitsWithMul (n `div` 2) (m * 2)

split :: Integral a => [a] -> Int -> [a]
split xs k = splitWithRedun xs (k - length xs)
    where splitWithRedun xs 0 = xs
          splitWithRedun (x:xs) k
            | x /= 1    = let hf = x `div` 2 in splitWithRedun (hf : hf : xs) (k - 1)
            | otherwise = 1 : splitWithRedun xs k

main = do
    s <- getLine
    let [n, k] = map read (words s) :: [Int]
    if k < popCount n || k > n then
        putStrLn "NO"
    else do
        putStrLn "YES"
        putStrLn (intercalate " " (map show (split (bits n) k)))