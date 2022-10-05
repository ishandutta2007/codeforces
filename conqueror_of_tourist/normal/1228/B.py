h, w = map(int,input().split())

r = list(map(int,input().split()))
c = list(map(int,input().split()))

l = [-1] * (h * w)

for i in range(h):
    tiles = r[i]

    for j in range(tiles):
        l[w * i + j] = 1

    if tiles < w:
        l[w * i + tiles] = 0

out = 1
for j in range(w):
    tiles = c[j]

    for i in range(tiles):
        pos = w * i + j
        if l[pos] == 0:
            out = -1
            break
        l[pos] = 1

    if tiles < h:
        pos = w * (tiles) + j
        if l[pos] == 1:
            out = -1
            break
        l[pos] = 0

M = 10**9+7

if out == -1:
    print(0)
else:
    count = 0
    for i in l:
        if i == -1:
            count += 1
    print(pow(2,count,M))