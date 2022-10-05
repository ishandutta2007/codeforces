import heapq

n, k = list(map(int, input().split()))
s = input()

mostRecent = n
best = []
for room in range(n-1, -1, -1):
    if s[room] == '1':
        mostRecent = room
    best.append(mostRecent)

best = best[::-1]

dp = [0]

vals = [(0,0)]

for room in range(1, n + 1):
    new = dp[-1] + room
    if room - k - 1 >= 0:
        bestRout = best[room - k - 1]
        if bestRout <= (room - 1):
            covered = bestRout - k

            if covered >= 0:
                try:
                    while len(vals) > 0 and vals[0][1] < covered:
                        heapq.heappop(vals)
                    if len(vals) > 0:
                        add = vals[0][0]
                        new2 = (bestRout + 1) + add
                        new = min(new2, new)
                except Exception:
                    pass
            else:
                new2 = (bestRout + 1)
                new = min(new2, new)



    dp.append(new)
    heapq.heappush(vals, (new, room))

print(new)