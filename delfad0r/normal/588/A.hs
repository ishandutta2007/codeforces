main = interact $ show . solve 100 . tail . map read . words
solve _ [] = 0
solve cMin (a : p : xs) = let nMin = min cMin p in nMin * a + solve nMin xs