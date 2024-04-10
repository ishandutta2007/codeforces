import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n, u, v = map(int, input().split())
    a = list(map(int, input().split()))

    passable = False
    
    if any(abs(a[i] - a[i+1]) >= 2 for i in range(n - 1)):
        out.append(0)
    elif all(z == a[0] for z in a):
        out.append(v + min(u,v))
    else:
        out.append(min(u,v))
print('\n'.join(map(str,out)))