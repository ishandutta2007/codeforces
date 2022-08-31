n = int(input())
for i in range(2, n + 1):
	if n % i == 0:
		print(str(i) + str(n // i))
		break