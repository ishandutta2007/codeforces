from sys import stdin
n, l, r = map(int, stdin.readline().split())

min_sum = n
for i in range(1, l):
    min_sum -= 1
    min_sum += 2 ** i

max_sum = n * (2 ** (r - 1))
for i in range(r):
    max_sum -= 2 ** (r - 1)
    max_sum += 2 ** i

print(min_sum, max_sum)