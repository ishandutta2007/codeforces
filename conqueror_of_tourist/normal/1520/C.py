t = int(input())

for _ in range(t):
    n = int(input())

    if n == 1:
        print(1)
    elif n == 2:
        print(-1)
    else:
        l = [[-1] * n for _ in range(n)]
        curr = 1
        
        for i in range(n):
            for j in range(n):
                if (i + j) % 2 == 0:
                    l[i][j] = curr
                    curr += 1

        for i in range(n):
            for j in range(n):
                if (i + j) % 2 == 1:
                    l[i][j] = curr
                    curr += 1

        for line in l:
            print(' '.join(map(str, line)))