from sys import stdin
for i in range(int(stdin.readline())):
    c, m, x = map(int, stdin.readline().split())
    def ok(nteam):
        return c >= nteam and m >= nteam and x + c + m >= 3 * nteam
    l = 0
    r = max(c, m, x) + 1
    while r - l > 1:
        mid = (r + l) // 2
        if ok(mid):
            l = mid
        else:
            r = mid
    print(l)