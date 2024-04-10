import sys
input = sys.stdin.readline

t = int(input())
out = []

for _ in range(t):
    s = input().strip()
    n = len(s)
    best = n + 1
    last1 = -best
    last2 = -best
    last3 = -best
    for i in range(n):
        c = s[i]
        if c == '1':
            last1 = i
        elif c == '2':
            last2 = i
        else:
            last3 = i
        curr = i - min(last1, last2, last3) + 1
        best = min(best, curr)
    if best <= n:
        out.append(best)
    else:
        out.append(0)
print(*out, sep = '\n')