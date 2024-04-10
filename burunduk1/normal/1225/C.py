def solve():
	n, p = map(int, input().split())
	for k in range(1, 32): #  
		# n = (2^x1 + p) + (2^x2 + p) + ....
		# n1 = n - kp = 2^x1 + 2^x2 + ...
		n1 = n - k * p 

		# n1 = 0101101010101011111
		#      0000000000100000000 -  
		#      0101101010001011111

		# n1 = 0101101010101011111  
		#      0000000001000000000 -  
		#      0101101001101011111

		# 2^0 = 1
		# b <= k <= n1

		if n1 < k:
			continue
		b = 0 #    n1

		#    b  

		while n1 > 0:
			b += n1 % 2
			n1 //= 2
		if b <= k:
			print(k)
			return
	print(-1)

solve()