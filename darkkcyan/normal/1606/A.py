for testcase in range(int(input())):
    s = input().strip()
    bal = 0
    sign = 1
    for u, v in zip(s[:-1], s[1:]):
        if u != v:
            bal += sign
            sign = -sign
    if bal != 0:
        s = s[:-1] + ('a' if s[-1] == 'b' else 'b')
    print(s)