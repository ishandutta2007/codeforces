T = int(input())

for i in range(T):

	n,k = [int(j) for j in input().split()]
	ls = [int(j) for j in input().split()]
	ls.reverse()

	ans = 0
	x = n - (n+1)//2 + 1
	for j in range(k):
		ans = ans + ls[x-1 + j*x]
	print(ans)