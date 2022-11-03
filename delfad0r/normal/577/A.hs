main = interact $ show . solve . map read . words
solve (n:x:[]) = length . filter (== 0) . map (x `mod`) $ [(x - 1) `div` n + 1 .. n]