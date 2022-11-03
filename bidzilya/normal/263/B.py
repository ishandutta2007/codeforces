def get_ints():
    return map(int, raw_input().strip().split(' '))

n, k = get_ints()
a = get_ints()

a.sort(reverse=True)

amount = 0
i = 0
ans = -1
while i < n:
    j = i
    while j + 1 < n and a[j + 1] == a[j]:
        j += 1
    amount += (j - i + 1)
    if amount == k:
        ans = a[i]
    i = j + 1

if ans == -1:
    print ans
else:
    print 0, ans