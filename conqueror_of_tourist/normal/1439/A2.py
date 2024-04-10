import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    table = [list(map(int,list(input().strip()))) for _ in range(n)]

    def add(a,b,c):
        table[a[0]][a[1]] = 1 - table[a[0]][a[1]]
        table[b[0]][b[1]] = 1 - table[b[0]][b[1]]
        table[c[0]][c[1]] = 1 - table[c[0]][c[1]]
        out.append(' '.join(map(lambda x: str(x+1),(a[0],a[1],b[0],b[1],c[0],c[1]))))

    out = []
    for i in range(n - 1, 1, -1):
        for j in range(m):
            if table[i][j]:
                if j + 1 < m:
                    add((i,j),(i-1,j),(i-1,j+1))
                else:
                    add((i,j),(i-1,j),(i-1,j-1))

    for j in range(m - 1, 1, -1):
        for i in range(2):
            if table[i][j]:
                if table[i][j]:
                    add((i,j),(0,j-1),(1,j-1))

    for i in range(2):
        for j in range(2):
            tot = table[0][0] + table[0][1] + table[1][0] + table[1][1]
            if (tot + table[i][j]) % 2:
                add((1-i,j),(1-i,1-j),(i,1-j))

    print(len(out))
    print('\n'.join(out))