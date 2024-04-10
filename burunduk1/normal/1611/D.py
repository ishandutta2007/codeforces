import sys

def solve():
	n = int(sys.stdin.readline())
	b = list(map(lambda s: int(s)-1, sys.stdin.readline().split()))
	d = 0
	ans = [-1] * n
	dist = [0] * n
	for v in map(lambda s: int(s)-1, sys.stdin.readline().split()):
		if b[v] == v: 
			ans[v] = 0
			continue
		if ans[b[v]] == -1: 
			return [-1]
		d += 1
		ans[v] = d - dist[b[v]]
		dist[v] = d
	return ans


tn = int(sys.stdin.readline())
for _ in range(tn):
	print(*solve())