for _ in range(int(input())):
    n = int(input())
    t = dict()
    d = dict()
    arr = list()
    for i in range(n):
        a, b = map(int, input().split())
        arr.append([a, b])
        try:
            t[a] += 1
        except:
            t[a] = 1
        try:
            d[b] += 1
        except:
            d[b] = 1
    ans = n*(n-1)*(n-2)//6
    for i in range(n):
        ans -= (t[arr[i][0]] - 1) * (d[arr[i][1]] - 1)
    print(ans)