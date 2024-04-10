def main():
    n, l = int(input()), list(map(int, input().split()))
    if not (n & 1):
        l.append(0)
    l.append(150001)
    a, b, fails, res = 0, 150001, [], 0
    for i, c in enumerate(l, -1):
        if i & 1:
            if a >= b or b <= c:
                if len(fails) > 5:
                    print(0)
                    return
                fails.append(i)
        else:
            if a <= b or b >= c:
                if len(fails) > 5:
                    print(0)
                    return
                fails.append(i)
        a, b = b, c
    ff = fails + [0]
    for i in fails:
        a = l[i]
        for j in range(n):
            l[i], l[j], ff[-1] = l[j], a, j
            if (all((l[b - 1] < l[b] > l[b + 1]) if b & 1 else
                    (l[b - 1] > l[b] < l[b + 1]) for b in ff)):
                res += 1 if j in fails else 2
            l[j] = l[i]
        l[i] = a
    print(res // 2)

main()