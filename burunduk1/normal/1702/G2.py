import sys, bisect, threading
sys.setrecursionlimit(10**8)
threading.stack_size(10**8)

def main():
	global T
	ix = lambda x: int(x)-1
	n = int(input())
	g = [[] for i in range(n)]
	for _ in range(n-1):
		a, b = map(ix, input().split())
		g[a].append(b)
		g[b].append(a)

	T = 0
	ts = [0] * n
	def go(v, p=-1):
		global T
		ts[v] = [T]
		T += 1
		for x in g[v]:
			if x != p:
				go(x, v)
				ts[v].append(T)
				T += 1
	go(0)

	def ancestor(a, b):
		return ts[a][0] <= ts[b][0] and ts[b][-1] <= ts[a][-1]
	def middle(a, b, c):
		i = bisect.bisect(ts[b], ts[a][0])
		return i < len(ts[b]) and ts[b][i] < ts[c][0]

	q = int(input())
	for _ in range(q):
		k = int(input())
		a = sorted(map(ix, input().split()), key = lambda v: ts[v][0])
		i = 1
		while i < len(a) and ancestor(a[i-1], a[i]):
			i += 1
		if i < len(a) and ((not ancestor(a[0], a[i])) or middle(a[1], a[0], a[i])): 
			i += 1
			while i < len(a) and ancestor(a[i-1], a[i]):
				i += 1
		print("YES" if i == len(a) else "NO")

thread = threading.Thread(target=main)
thread.start()
thread.join()