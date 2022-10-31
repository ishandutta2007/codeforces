from collections import deque

n, d = map(int, raw_input().split())
a = [0] + map(int, raw_input().split()) + [0]
p = [map(int, raw_input().split()) for i in xrange(n)]

l = 1
r = 10 ** 9
ans = r
while l <= r:
    m = (l + r) // 2
    v = [-1] * n
    inq = [False] * n
    q = deque([0])
    v[0] = m
    while len(q) > 0:
        x = q.popleft()
        inq[x] = False
        for i in xrange(n):
            if i == x:
                continue
            dist = abs(p[x][0] - p[i][0]) + abs(p[x][1] - p[i][1])
            if v[x] >= dist * d:
                nv = v[x] - dist * d + a[i]
                if nv > v[i]:
                    v[i] = nv
                    if not inq[i]:
                        q.append(i)
                        inq[i] = True
    if v[n - 1] >= 0:
        r = m - 1
        ans = m
    else:
        l = m + 1

print ans