import sys
# input = sys.stdin.readline

def solve():
	f = lambda x : x * 239017 + 17239
	input()
	n, q = map(int, input().split())
	left = {}
	right = {}
	a = list(enumerate(map(int, input().split())))
	for i, x in a: right[f(x)] = i
	for i, x in a[::-1]: left[f(x)] = i
	for iq in range(q):
		a, b = map(int, input().split())
		print("YES" if left.get(f(a), n) < right.get(f(b), -1) else "NO")

tn = int(input())
for _ in range(tn):
	solve()