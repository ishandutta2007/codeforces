t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    pref = [0]
    for v in l:
        pref.append(pref[-1] + v)
    seen = dict()
    for v in l:
        if v not in seen:
            seen[v] = 0
        seen[v] += 1

    count = 0
    for i in range(n + 1):
        for j in range(i + 2, n + 1):
            nex = (pref[j] - pref[i])
            if nex in seen:
                count += seen[nex]
                del seen[nex]
    print(count)