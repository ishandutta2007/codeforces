from math import gcd


for _ in range(int(input())):
    s, x = input().split()
    x = int(x)
    ans = 0
    for i in range(1440//gcd(1440, x)):
        if(s[0] == s[4] and s[1] == s[3]):
            ans += 1
        y = x
        hour = int(s[0])*10 + int(s[1])
        minute = int(s[3])*10 + int(s[4])
        while(y > 0):
            if(minute + y >= 60):
                y -= 60 - minute
                minute = 0
                hour += 1
                if(hour == 24):
                    hour = 0
            else:
                minute += y
                y = 0
        t = str(hour)
        u = str(minute)
        if(len(t) == 1):
            t = "0" + t
        if(len(u) == 1):
            u = "0" + u
        s = t + ":" + u
    print(ans)