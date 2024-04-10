n = int(input())
a = list(map(int, input().split()))


fst = [-1] * (n + 1)
right = [-1] * n

for i in range(n):
    v = a[i]
    if fst[v] == -1:
        fst[v] = i
    right[fst[v]] = i

out = 0

left = 0
dist = 0
mdist = 0
r = -1

for i in range(n):
    r = max(r, right[i])

    #print(i, left, dist, mdist, r)

    if r == i:
        out += r - left - dist

        left = i + 1
        dist = 0
        mdist = i + 1
        r = -1
    else:
        if mdist == i:
            dist += 1
            mdist = r

print(out)