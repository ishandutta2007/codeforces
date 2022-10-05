import sys
input= sys.stdin.readline
t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int,input().split()))

    smol = l[0]
    works = True
    for i in range(1, n):
        if l[i] == l[i-1] + 1:
            pass
        else:
            if l[i] > smol:
                works = False
                break
        smol = min(smol, l[i])

    if works:
        out.append('Yes')
    else:
        out.append('No')
print('\n'.join(out))