for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = arr[0]
    sub = 0
    for i in range(n - 1):
        sub += arr[i] - sub
        ans = max(ans, arr[i+1] - sub)
    print(ans)