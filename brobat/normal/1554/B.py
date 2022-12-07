for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    start = max(0, n-205)
    ans = -100000000000
    for i in range(start, n):
        for j in range(start, n):
            if(i!=j):
                ans = max(ans, (i+1)*(j+1) - (k*(arr[i]|arr[j])))
    print(ans)