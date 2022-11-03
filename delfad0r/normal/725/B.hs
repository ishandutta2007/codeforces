main = do
	i <- getLine
	let n = read $ init i :: Integer;
		p = last i
	let ans = (((n - 1) `div` 4) * 2 + 1 - (n `mod` 2)) * 6 + ((n - 1) `div` 4) * 4 + 1 - (n `mod` 2)
	print $ ans + f p
	where
		f 'f' = 1
		f 'e' = 2
		f 'd' = 3
		f 'a' = 4
		f 'b' = 5
		f 'c' = 6