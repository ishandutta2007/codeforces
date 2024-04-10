import copy

s = list(input())
n = len(s)
ans = 0
for i in range(0, n + 1):
    t = copy.copy(s)
    if i < n:
        if t[i] == 'V':
            t[i] = 'K'
        else:
            t[i] = 'V'
    tot = 0
    for j in range(0, n - 1):
        if t[j] == 'V' and t[j + 1] == 'K':
            tot = tot + 1
    if ans < tot:
        ans = tot
print(ans)