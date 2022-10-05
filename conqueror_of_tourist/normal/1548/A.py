import sys
input = sys.stdin.readline

n,m = map(int, input().split())
bad = [0] * n
out = n

for _ in range(m):
    u, v = map(int, input().split())
    if u > v:
        u,v=v,u
    if bad[u-1] == 0:
        out -= 1
    bad[u-1] += 1

outL = []
q = int(input())
for _ in range(q):
    qu = list(map(int, input().split()))
    if qu[0] == 1:
        u = min(qu[1], qu[2])
        if bad[u-1] == 0:
            out -= 1
        bad[u-1] += 1
    elif qu[0] == 2:
        u = min(qu[1], qu[2])
        bad[u-1] -= 1
        if bad[u-1] == 0:
            out += 1
    else:
        outL.append(out)
print('\n'.join(map(str,outL)))