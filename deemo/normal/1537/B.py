te = int(input())
while te > 0:
    te -= 1
    n, m, i, j = map(int, input().split())
    lst = [
        [1, 1],
        [n, 1],
        [1, m],
        [n, m],
    ]
    mx = -1
    for x in lst:
        for y in lst:
            temp = abs(i-x[0]) + abs(j-x[1]) + abs(y[0]-x[0]) + abs(y[1]-x[1]) + abs(i-y[0]) + abs(j-y[1])
            mx = max(mx, temp)
    for x in lst:
        for y in lst:
            temp = abs(i-x[0]) + abs(j-x[1]) + abs(y[0]-x[0]) + abs(y[1]-x[1]) + abs(i-y[0]) + abs(j-y[1])
            if temp == mx:
                ans = [x, y]

    x, y = ans
    print(x[0], x[1], y[0], y[1]);