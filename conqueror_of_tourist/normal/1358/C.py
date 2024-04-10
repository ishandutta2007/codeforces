import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    a, b, c, d = map(int, input().split())
    dX = c - a
    dY = d - b
    out.append(dX * dY + 1)
    

print('\n'.join(map(str,out)))