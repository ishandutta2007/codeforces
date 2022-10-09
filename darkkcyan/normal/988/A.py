n, k = map(int, input().split())
a = list(map(int, input().split()))

dct = {}
for i in range(n):
    dct[a[i]] = i + 1
if len(dct) < k:
    print('NO')
else:
    print('YES')
    for val in dct.values():
        print(val, end=" ")
        k -= 1
        if k == 0:
            break