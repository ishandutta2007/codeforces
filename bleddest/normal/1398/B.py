t = int(input())

for i in range(t):
    s = input()
    s2 = list(s.split('0'))
    a = map(len, s2)
    a = sorted(a)[::-1]
    ans = 0
    for j in range(0, len(a), 2):
        ans += a[j]
    print(ans)