for _ in range(int(input())):
    s = input()
    d = dict()
    for i in range(len(s)):
        try:
            d[s[i]] += 1
        except:
            d[s[i]] = 1
    ans = 0
    for i in d:
        ans += min(d[i], 2)
    print(ans//2)