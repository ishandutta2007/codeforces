n, k = map(int, input().split())
a = sorted([len(input()) for i in range(n)])
b = len(input())

ans1, ans2 = 0, 0
for i in range(n):
    ans1 += 1
    if a[i] == b:
        break
    if i % k == k - 1:
        ans1 += 5
for i in range(n):
    ans2 += 1
    if i == n - 1 or a[i + 1] > b:
        break
    if i % k == k - 1:
        ans2 += 5
print(ans1, ans2)