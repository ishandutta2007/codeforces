T = int(input())

for _ in range(T):

	n,x = [int(i) for i in input().split()]

	a = [int(i) for i in input().split()]
	b = [int(i) for i in input().split()]

	ans = True
	for i in range(n):
		if b[i] + a[-i-1] > x :
			ans = False

	if ans:
		print("Yes")
	else:
		print("No")
	if _<T-1:
		input()