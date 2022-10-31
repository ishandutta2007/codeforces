n = input()
a = map(int, raw_input().split())
ans = 0
for i in xrange(1, n - 1):
    if a[i] > a[i - 1] and a[i] > a[i + 1]:
        ans += 1
    if a[i] < a[i - 1] and a[i] < a[i + 1]:
        ans += 1
print ans