import sys
input = sys.stdin.readline

t = int(input())
outL = []
for _ in range(t):
    n = int(input())
    x = list(map(int, input().split()))
    x.sort()
    
    out = 0
    big = -1
    for v in x:
        if v > big:
            out += 1
            big = v
        elif v == big:
            out += 1
            big  =v + 1
    outL.append(out)
print('\n'.join(map(str,outL)))