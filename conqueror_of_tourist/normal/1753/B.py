n, x = map(int, input().split())
a = list(map(int, input().split()))

l = [0] * (x + 1)
for v in a:
    l[v] += 1

bad = False

for i in range(1, x):
    l[i + 1] += l[i] // (i + 1)
    l[i] %= i + 1

    if l[i]:
        bad = True

if bad:
    print('No')
else:
    print('Yes')