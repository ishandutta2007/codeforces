ans :: [Integer] -> String
ans (x : xs) = if ((x `mod` 2 == 0) && (x > 2)) then "YES" else "NO"

main = do
    d <- getLine
    putStr (ans (map read (words d)))