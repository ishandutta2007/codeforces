
    # n = int(input())
n, k = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
for i in range(n):
    arr[i] = 5 - arr[i]
    if(arr[i]>=k):
        ans += 1
print(ans//3)