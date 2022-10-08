mem = dict()
def go(n):
	global m
	if n > m: return m+1
	if n == m: return 0
	if n in mem: return mem[n]
	mem[n] = 1 + min(go(2 * n), go(3 * n))
	return mem[n]

n, m = map(int, input().split())
ans = go(n)
print(-1 if ans > m else ans)