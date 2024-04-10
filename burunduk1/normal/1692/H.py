import sys
input = sys.stdin.readline

def f(x): return x * 239017 + 170239
def f1(x): return (x - 170239) // 239017

def solve():
	n = int(input())
	
	last = {}
	task = {}
	i = 0
	prev = -1
	for x in map(int, input().split()):
		if not f(x) in last:
			task[f(x)] = [-i]
		elif x != prev:
			task[f(x)].append(-(i - last[f(x)] - 1))
		task[f(x)].append(1)
		last[f(x)] = i
		i += 1
		prev = x

	best_l, best_r, best_x, best = 0, 0, 0, -1
	for fx in task:
		s, il, ir = 0, 0, 0
		for b in task[fx]:
			s += b
			ir += 1 if b > 0 else -b
			if s < 0:
				il, s = ir, 0
			if s > best:
				best_l, best_r, best_x, best = il, ir, f1(fx), s
	return "%d %d %d" % (best_x, best_l + 1, best_r)

print("\n".join([solve() for _ in range(int(input()))]))