for _ in range(int(input())):
    n = int(input())
    if(n%2050!=0):
        print(-1)
        continue
    else:
        n //= 2050
        s = str(n)
        ans = 0
        for i in range(len(s)):
            ans += int(s[i])
        print(ans)