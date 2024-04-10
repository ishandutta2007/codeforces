T = int(input())

for _ in range(T):

	n,m = [int(j) for j in input().split()]

	ans = 0
	Min = 3e9
	val = 0
	for i in range(n):
		ls = [int(j) for j in input().split()]
		for j in ls:
			ans = ans + abs(j)
			if j < 0 :
				val = val + 1
			Min = min(Min,abs(j))
	if val % 2 == 1:
		ans = ans - 2*Min
	print(ans)