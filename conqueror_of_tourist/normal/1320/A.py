vals = dict()

n = int(input())
l = list(map(int, input().split()))

for i in range(n):
    beaut = l[i]

    ind = beaut - i
    if ind not in vals:
        vals[ind] = 0
    vals[ind] += beaut

best = 0
for v in vals:
    if vals[v] > best:
        best = vals[v]

print(best)