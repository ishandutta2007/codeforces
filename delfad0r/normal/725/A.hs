main = do
	getLine
	x <- getLine
	print $ (length $ takeWhile (== '<') x) + (length $ takeWhile (== '>') $ reverse x)