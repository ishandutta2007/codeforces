n = int(input())
a = list(map(int, input().split()))
a.sort(key=None, reverse=True)
res = a[0];
for i in range(1,n):
    while a[i] >= a[i - 1]:
        a[i] -= 1
    if a[i] > 0:
        res += a[i]
print(res)