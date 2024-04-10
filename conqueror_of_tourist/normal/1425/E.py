n, k = map(int, input().split())
a = list(map(int, input().split()))
d = list(map(int, input().split()))

if k == 0:
    best = 0
    curr = sum(a)
    for i in range(n):
        best = max(best, curr - d[i])
        curr -= a[i]
    print(best)
elif k == 1:
    best = sum(a[:-1]) - min(d[:-1])
    
    other = sum(a)
    other -= sorted(d)[0]
    other -= sorted(d)[1]

    curr = sum(a)
    for i in range(n):
        if i:
            best = max(best, curr - d[i])
        curr -= a[i]

    o2 = sum(a) - min(a[1:]) - d[0]
    
    print(max((best,other,0, o2)))
else:
    print(max((sum(a) - min(d[:-1]),0,a[-1] - d[-1])))