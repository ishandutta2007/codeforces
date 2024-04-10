n, m = map(int, input().split())
l = list(map(int, input().split()))
out = []
curr = 0
lastPoss = [n - l[i] for i in range(m)]
for i in range(m - 2, -1, -1):
    lastPoss[i] = min(lastPoss[i], lastPoss[i+1]-1)

if lastPoss[0] < 0:
    print(-1)
else:
    for i in range(m):
        v = l[i]
        out.append(min(curr,lastPoss[i]))
        curr += v

    if curr >= n:
        print(' '.join(map(lambda x: str(x+1),out)))
    else:
        print(-1)