import sys
input = sys.stdin.readline

oo = []
t = int(input())
for _ in range(t):
    n = int(input())
    x = list(map(int, input().split()))

    mx = x[-1]
    out = 0
    for v in x[::-1]:
        if v > mx:
            out += 1
            mx = v
    oo.append(out)
print('\n'.join(map(str,oo)))