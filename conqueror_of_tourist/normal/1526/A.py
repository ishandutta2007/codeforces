t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()
    out = []
    for x, y in zip(l[:n],l[n:]):
        out.append(x)
        out.append(y)
    print(' '.join(map(str,out)))