import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    l = []
    n, m = map(int, input().split())

    for _ in range(n):
        l.append(list(map(int, input().split())))

    works = True
    for i in range(n):
        for j in range(m):
            s1 = 2 if min(i,n-1-i) else 1
            s2 = 2 if min(j,m-j-1) else 1
            s = s1 + s2

            if l[i][j] <= s:
                l[i][j] = s
            else:
                works = False
                break

    if works:
        print('YES')
        outs = [' '.join(map(str,ll)) for ll in l]
        print('\n'.join(outs))
    else:
        print('NO')