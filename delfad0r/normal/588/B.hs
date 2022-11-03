main = interact $ show . solve 1 primes . read
solve ans (p : ps) n
	|p * p > n      = ans * n
	|n `mod` p == 0 = solve (ans * p) ps $ n `div` p ^ (last $ takeWhile (\x -> n `mod` p ^ x == 0) [1 ..])
	|otherwise      = solve ans ps n
primes = 2 : 3 : filter (\n -> all (\x -> n `mod` x /= 0) . takeWhile (\x -> x * x <= n) $ primes) [5 ..]