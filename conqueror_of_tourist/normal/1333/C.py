n = int(input())
seen = dict()
seen[0] = 0
out = 0
l = list(map(int,input().split()))
curr = 0
bestCurr = 0
for i in range(n):
    curr += l[i]
    if curr in seen:
        bestCurr = min(bestCurr + 1, i - seen[curr])
    else:
        bestCurr += 1
    out += bestCurr
    seen[curr] = i + 1
print(out)