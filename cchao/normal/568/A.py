maxn = 2000000

vis = [False] * maxn
vis[0] = vis[1] = True
for i in xrange(2, maxn):
    if not vis[i]:
        for j in xrange(i * 2, maxn, i):
            vis[j] = True

def isPalin(x):
    l = []
    while x > 0:
        l.append(x % 10)
        x /= 10
    n = len(l)
    for i in xrange(n / 2):
        if l[i] != l[n - i - 1]:
            return False
    return True

p, q = map(int, raw_input().split())
ans = 0
aa = 0
bb = 0
for i in xrange(1, maxn):
    if not vis[i]:
        aa = aa + 1
    if isPalin(i):
        bb = bb + 1
    if q * aa <= p * bb:
        ans = i

print ans