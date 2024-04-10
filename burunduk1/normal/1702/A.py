def solve():
	n = input()
	print(int(n)-10**(len(n)-1))

tn = int(input())
for _ in range(tn):
	solve()