for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    x = min(arr)
    ans = 0
    for i in arr:
        if i==x:
            ans += 1
    print(n-ans)