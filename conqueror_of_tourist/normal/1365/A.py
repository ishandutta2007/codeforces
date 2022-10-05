t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    l = []
    for i in range(n):
        l.append(list(map(int, input().split())))

    emptyRows = 0
    for i in range(n):
        for j in range(m):
            if l[i][j] == 1:
                break
        else:
            emptyRows += 1

    emptyCols = 0
    for j in range(m):
        for i in range(n):
            if l[i][j] == 1:
                break
        else:
            emptyCols += 1

    out = min(emptyCols, emptyRows)
    if out % 2:
        print('Ashish')
    else:
        print('Vivek')