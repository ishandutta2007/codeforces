import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    m, n = map(int, input().split())
    l = []
    for i in range(m):
        l.append(input().strip())
    out = 0
    for i in range(m):
        if l[i][-1] == 'R':
            out += 1
    for c in l[-1]:
        if c == 'D':
            out += 1
    print(out)