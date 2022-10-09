from sys import stdin

n = int(stdin.readline())
c = list(map(int, stdin.readline().split()))
u = n - 1
v = 0
while c[u] == c[0]:
    u -= 1
while c[v] == c[-1]:
    v += 1
print(max(u, n - 1 - v))