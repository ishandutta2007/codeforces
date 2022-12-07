for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 10000000000
    arr.sort()
    for i in range(n-1):
        ans = min(ans, arr[i+1]-arr[i])
    print(ans)