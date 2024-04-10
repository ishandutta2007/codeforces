n, k = map(int, input().split())
a = sorted(map(int, input().split()), reverse = True)
while len(a) > 0 and a[-1] <= k:
    a.pop()

a.append(k)
ans = 0
while len(a) > 1:
    u, v= a[-1], a[-2]
    while u * 2 < v:
        ans += 1
        u *= 2
    a.pop()
print(ans)