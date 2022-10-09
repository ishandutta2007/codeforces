n = int(input())
s = list(map(lambda c: c == '1', input().strip()))
lights = [list(map(int, input().split())) for i in range(n)]

ans = 0
for time in range(1000):
    for cur in range(n):
        if time < lights[cur][1]:
            continue
        if (time - lights[cur][1]) % lights[cur][0] == 0:
            s[cur] = not s[cur]
    ans = max(ans, sum(int(i) for i in s))
print(ans)