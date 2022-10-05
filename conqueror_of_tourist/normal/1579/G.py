t = int(input())
for _ in range(t):
    best = [0] * 3000
    n = int(input())
    l = map(int, input().split())
    for d in l:
        nex = []
        for i in range(3000):
            p1 = best[i + d] + d if i < 3000 - d else 10000
            p2 = max(0, best[i - d] - d) if i >= d else 10000
            nex.append(min(p1, p2))
        best = nex
    for i in range(3000):
        best[i] += i
    print(min(best))