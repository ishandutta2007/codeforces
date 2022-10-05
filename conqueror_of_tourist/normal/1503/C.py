import sys
input = sys.stdin.readline

n = int(input())
l = []
out = 0
for _ in range(n):
    a, c = map(int, input().split())
    out += c
    l.append((a,c))

l.sort(key = lambda x: x[0])

curr_best = l[0][0]
for a, c in l:
    if a > curr_best:
        out += (a - curr_best)
    curr_best = max(curr_best, a+c)
print(out)