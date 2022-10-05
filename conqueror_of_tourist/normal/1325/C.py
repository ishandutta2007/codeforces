import sys
input = sys.stdin.readline

n = int(input())
verts = [-1] * n
for e in range(n - 1):
    a, b = map(int, input().split())

    for v in (a-1, b-1):
        if verts[v] == -1:
            verts[v] = e
        else:
            verts[v] = -2

good = set()
for e in verts:
    if e > -1:
        good.add(e)

out = []
smol = 0
tol = 0

for e in range(n-1):
    if e in good:
        tol += 1

for e in range(n - 1):
    if e in good:
        out.append(smol)
        smol += 1
    else:
        out.append(tol)
        tol += 1
print('\n'.join(map(str,out)))