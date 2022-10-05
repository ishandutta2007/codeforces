import sys
input = sys.stdin.readline

n,q = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a)
out = []

for i in range(q):
    t, x = map(int, input().split())
    if t == 1:
        s -= a[x - 1]
        a[x - 1] = 1 - a[x - 1]
        s += a[x - 1]
    else:
        if x <= s:
            out.append(1)
        else:
            out.append(0)
print('\n'.join(map(str,out)))