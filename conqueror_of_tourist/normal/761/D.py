n, l, r = map(int, input().split())
a = list(map(int, input().split()))
out = [-1] * n
p = list(map(int, input().split()))
pp = [(p[i],i) for i in range(n)]
pp.sort()

curr = -(l+r)
for v, i in pp:
    best = curr + 1 + a[i]
    if best < l:
        best = l
    out[i] = best
    curr = best - a[i]

if max(out) > r:
    print(-1)
else:
    print(' '.join(map(str,out)))