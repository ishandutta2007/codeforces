n = int(input())
a = list(map(int, input().split()))
l, r = 0, n - 1
ans = [0, 0]
m = 0
while l <= r:
    if a[l] > a[r]:
        ans[m] += a[l]
        l += 1
    else:
        ans[m] += a[r]
        r -= 1
    m ^= 1

print(ans[0], ans[1])