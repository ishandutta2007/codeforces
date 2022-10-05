import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m, x, y = map(int, input().split())
    if y > 2 * x:
        y = 2 * x
    out = 0
    for i in range(n):
        line = input().strip()

        curr = 0
        for c in line:
            if c == '.':
                out += y * curr
                curr = 1 - curr
            else:
                out += x * curr
                curr = 0
        out += x * curr
    print(out)