import sys
input = sys.stdin.readline

out = []
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if n < 2 * k - 1:
        out.append(-1)
        continue

    for i in range(n):
        s = []
        for j in range(n):
            if i == j and i % 2 == 0 and i <= 2 * k - 1:
                s.append('R')
            else:
                s.append('.')
        out.append(''.join(s))
print('\n'.join(map(str,out)))