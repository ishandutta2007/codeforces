#!/usr/bin/python3

def solve(n, t):
	x0 = 1;
	for i in range(1, n):
		x0 *= 10;
	
	
	for x in range(x0, 10 * x0):
		if (x % t == 0):
			return x
	return -1

nums = list(map(int, input().split()))
print(solve(nums[0], nums[1]))