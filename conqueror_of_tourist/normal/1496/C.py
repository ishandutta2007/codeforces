import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    xs = []
    ys = []
    n = int(input())
    for _ in range(2 * n):
        a, b = map(int, input().split())
        if a:
            xs.append(a * a)
        else:
            ys.append(b * b)
    xs.sort()
    ys.sort()
    out = 0
    for a, b in zip(xs, ys):
        out += (a + b) ** (0.5)
    print(out)