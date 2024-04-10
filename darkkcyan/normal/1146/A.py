from sys import stdin

s = stdin.readline()
n = len(s)
na = sum(1 for i in s if i == 'a')
print(min(n - 1, na * 2 - 1))