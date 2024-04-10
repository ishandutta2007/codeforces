t = int(input())
for _ in range(t):
    n = int(input())
    l = map(int,input().split())
    out = 0
    curr = 0
    for v in l:
        if (curr >= 0) ^ (v >= 0):
            out += curr
            curr = v
        else:
            curr = max(v,curr)
    print(out+curr)