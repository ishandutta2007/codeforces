for testcase in range(int(input())):
    n = input().strip()
    ans = len(n)
    if '0' in n:
        ans = len(n) - 1
    for d in range(0, 100, 25):
        d1 = d % 10
        d2 = d // 10 % 10
        u = n.rfind(str(d1))
        if u == -1:
            continue
        v = n.rfind(str(d2), 0, u)
        if v == -1:
            continue
        ans = min(ans, len(n) - v - 2)
    print(ans)