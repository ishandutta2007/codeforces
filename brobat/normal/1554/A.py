for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    for i in range(n-1):
        ans = max(ans, arr[i]*arr[i+1])
    print(ans)