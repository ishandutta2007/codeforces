main = interact $ solve . map read . words
solve (_:xs) = if allEqual . map f $ xs then "Yes" else "No"
	where
		f x
			| x `mod` 2 == 0	= f (x `div` 2)
			| x `mod` 3 == 0	= f (x `div` 3)
			| otherwise			= x
		allEqual (x:xs)			= and . map (== x) $ xs