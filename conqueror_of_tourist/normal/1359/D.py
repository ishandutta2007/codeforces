n = int(input())
l = list(map(int,input().split()))

curr = 0
best = 0
prevs = [0] * 31
for v in l:
    curr += v
    if v >= 0:
        for i in range(0, v):
            prevs[i] = curr
        for i in range(v, 31):
            best = max(curr - prevs[i] - i, best)
    else:
        for i in range(31):
            prevs[i] = min(prevs[i], curr)
print(best)