T = int(input())

for _ in range(T):

	a,b,c,d = [int(x) for x in input().split()]
	print(max(a+b,c+d))