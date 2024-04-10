T = int(input())

for i in range(T):

	n,c0,c1,h = [int(j) for j in input().split()]
	s = str(input())
	ans = 0
	for c in s:
		if c == '1':
			ans = ans + min(c1,h+c0)
		else :
			ans = ans + min(c0,h+c1)
	print(ans)