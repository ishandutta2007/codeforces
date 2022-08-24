n = int(input())
line = list(map(int, input().split()))
m = dict()
ans = 0
for i in range(n):
    if line[i] not in m:
        m[line[i]] = 1
    else:
        m[line[i]] += 1
    var = m[line[i]]
    if line[i] - 1 in m:
        var += m[line[i]-1]
    if line[i] + 1 in m:
        var += m[line[i]+1]
    ans += (i+1-var) * line[i]
x = dict()
for j in range(n):
    i = n - j - 1
    if line[i] not in x:
        x[line[i]] = 1
    else:
        x[line[i]] += 1
    var = x[line[i]]
    if line[i] - 1 in x:
        var += x[line[i]-1]
    if line[i] + 1 in x:
        var += x[line[i]+1]
    ans -= (j+1-var) * line[i]
print(ans)