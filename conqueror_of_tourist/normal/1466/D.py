import sys
input = sys.stdin.readline

t = int(input())
outL = []
for _ in range(t):
    n = int(input())
    w = list(map(int, input().split()))
    extra = []
    deg = [0] * n
    for i in range(n-1):
        for v in map(int, input().split()):
            vv = v - 1
            if deg[vv]:
                extra.append(w[vv])
            deg[vv] += 1
        
    out = [sum(w)]
    extra.sort(reverse = True)
    for v in extra:
        out.append(out[-1] + v)
    outL.append(' '.join(map(str,out)))

print('\n'.join(outL))