import sys

n, m, a = map(int, sys.stdin.readline().split())
print ((n + a - 1) / a) * ((m + a - 1) / a)