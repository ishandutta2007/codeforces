n = int(input())
l = list(map(float, input().split()))
l.sort(reverse = True)

best = 0

curr0 = 1
curr1 = 0
for v in l:
    curr1 *= (1 - v)
    curr1 += v * curr0
    curr0 *= (1 - v)
    best = max(curr1, best)
print(best)