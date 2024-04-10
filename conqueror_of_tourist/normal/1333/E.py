n = int(input())
if n <= 2:
    print(-1)
else:
    out = [[0] * n for i in range(n)]
    out[0][0] = 9
    out[0][1] = 3
    out[0][2] = 1
    out[1][0] = 7
    out[1][1] = 8
    out[1][2] = 5
    out[2][0] = 6
    out[2][1] = 2
    out[2][2] = 4
    flip = True
    for i in range(3, n):
        if flip:
            for j in range(i+1):
                out[j][i] = i * i + j + 1
            for j in range(i):
                out[i][j] = (i + 1) * (i + 1) - j
        else:
            for j in range(i+1):
                out[i][j] = i * i + j + 1
            for j in range(i):
                out[j][i] = (i + 1) * (i + 1) - j
        
    for l in out:
        print(' '.join(map(lambda x: str(n * n + 1 - x), l)))