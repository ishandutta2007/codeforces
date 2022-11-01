R = lambda: map(int, raw_input().split())
n, t = R()
ans = 0
for x in R():
    ans += 1
    t -= 86400 - x
    if t <= 0:
        print ans
        quit()