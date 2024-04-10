n = int(input())
for i in range(2, min(100000, n)):
	if n % i == 0:
		if (i == 2):
			print(n // 2)
		else:
			print((n - i) // 2 + 1)
		break;
else:
	print(1)