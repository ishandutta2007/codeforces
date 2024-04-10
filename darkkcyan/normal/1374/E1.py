n, k = map(int, input().split())
group = [[], [], [], []]
for i in range(n):
    t, a, b = map(int, input().split())
    group[a * 2 + b].append(t)

pref_sum = [[0], [0], [0], [0]]
for g, ps in zip(group, pref_sum):
    g.sort()
    for i in g:
        ps.append(ps[-1] + i)

# print(group) 
# print(pref_sum) 
ans = 10**18
for i in range(min(k, len(group[3])) + 1):
    rest = k - i
    if rest > len(group[2]) or rest > len(group[1]):
        continue
    ans = min(ans, pref_sum[3][i] + pref_sum[1][rest] + pref_sum[2][rest])

if ans < 10**18:
    print(ans)
else:
    print(-1)