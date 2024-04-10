import Control.Applicative

main = do
    ans <- map (show . solve . read) . tail . words <$> getContents
    sequence_ . map putStrLn $ ans

solve n = n * (n + 1) `div` 2 - 2 * (sum . takeWhile (<= n) . map (2 ^) $ [0 ..])