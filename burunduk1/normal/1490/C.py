# def solve(n):
# 	a = 1
# 	while a * a * a < n:
# 		b = round((n - a * a * a)**(1/3)) # error < 0.5
# 		if a * a * a + b * b * b == n:
# 			return True
# 		a += 1
# 	return False

def solve(n):
	a = 1
	b = round(n**(1/3))
	while a * a * a < n:
		while a * a * a + b * b * b > n:
			b -= 1
		if a * a * a + b * b * b == n:
			return True
		a += 1
	return False

tn = int(input())
for _ in range(tn):
	print("YES" if solve(int(input())) else "NO")

# import math

# x = round(1.5)
# print(x)
# print(type(x))