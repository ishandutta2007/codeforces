for _ in range(int(input())):
    x = input()
    d = dict()
    for i in range(26):
        d[x[i]] = i
    ans = 0
    s = input()
    for i in range(1, len(s)):
        if(s[i]==s[i-1]):
            continue
        ans += abs(d[s[i]] - d[s[i-1]])
    print(ans)