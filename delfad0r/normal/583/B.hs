main = interact $ show . solve 0 0 . tail . map read . words

solve ans _ [] = ans - 1
solve ans k l = let (newK, newL) = foldl (\(k, l) v -> if v > k then (k, v : l) else (k + 1, l)) (k, []) l in solve (ans + 1) newK newL