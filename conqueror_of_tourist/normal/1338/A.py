import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    big = l[0]
    need = 0
    for v in l:
        if v < big:
            need = max(need, big - v)
        else:
            big = v
            
    curr = 0
    p = 0
    while p < need:
        curr += 1
        p *= 2
        p += 1
    out.append(curr)

print('\n'.join(map(str,out)))