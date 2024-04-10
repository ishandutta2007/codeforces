# -*- coding: utf-8 -*-

import sys, threading

input = sys.stdin.readline
sys.setrecursionlimit(10**8)
threading.stack_size(10**8)

def my_tracer(frame, event, arg = None):
	code = frame.f_code
	func_name = code.co_name
	line_no = frame.f_lineno
	print(f"A {event} encountered in {func_name}() at line number {line_no}")
	return my_tracer
# sys.settrace(my_tracer)

# # 1. index of out range
# b = [0] * 3
# b[4] = 2

# # 2. division by zero
# a = 3 / 0

# 3. stack overflow
# def f():
# 	f()
# f()

def solve():
	n = int(input())
	g = [[] for i in range(n)]
	# g[n + 1] = 3
	indexes = [list() for i in range(n+1)]
	solve.failed = False
	for i in range(n):
		a, b = map(int, input().split()) 
		if a == b: solve.failed = True
		def add(value, index):
			indexes[value].append(index)
		add(a, i)
		add(b, i)

	for value, s in enumerate(indexes):
		solve.failed |= (len(s) >= 3)
		if len(s) == 2:
			def addEdge(a, b):
				g[a].append(b)
				g[b].append(a)
			addEdge(s[0], s[1])

	used = [0] * n
	# a=1 -> b=2 -> c=1 -> a=2
	# 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 
	# (1 2) (2 3) (3 4) (4 5) (5 6) ...
	def dfs(v, color):
		# print(v, color)
		if used[v]:
			solve.failed |= (used[v] != color)
			return
		used[v] = color
		for x in g[v]: #  
			dfs(x, 3 - color) # 1+2=3, 1 -> 2, 2 -> 1

	for i in range(n):
		if not used[i]:
			dfs(i, 1)

	# condition ? a : b
	print("YES" if not solve.failed else "NO")

def main():
	tn = int(input())
	for t in range(tn):
		solve()

# main()
thread = threading.Thread(target=main)
thread.start()
thread.join()