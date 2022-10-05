t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    l = map(int, input().split())
    
    d = dict()
    d[0] = 0
    for v in l:
        vv = (k - v) % k
        if vv:
            if vv not in d:
                d[vv] = vv + 1
            else:
                d[vv] += k
    print(max(d.values()))