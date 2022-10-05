def num(c):
    return ord(c) - 97

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s1 = input().strip()
    s2 = input().strip()

    char1 = [0] * 26
    char2 = [0] * 26
    for c in s1:
        char1[num(c)] += 1
    for c in s2:
        char2[num(c)] += 1
    if char1 != char2:
        print(-1)
        continue

    dp = [[(False, 0, 0) for j in range(n+1)] for i in range(n + 1)]
    dp[0][0] = [True, 0,[0]*26]

    def upd(a, b, val, sett):
        if not dp[a][b][0] or val > dp[a][b][1]:
            dp[a][b] = (True, val, sett)
    
    for i in range(n):
        for j in range(n):
            valid, val, tab = dp[i][j]
            if not valid:
                continue
            
            top = s1[i]
            bot = s2[j]

            if top == bot:
                #upd(i+1, j+1, val + 1, tab)
                if not dp[i + 1][j + 1][0] or val + 1 > dp[i + 1][j + 1][1]:
                    dp[i + 1][j + 1] = [True, val + 1, tab]

            if tab[num(top)] > 0:
                sett = tab[:]
                sett[num(top)] -= 1
                
                #upd(i+1, j, val, sett)
                if not dp[i + 1][j][0] or val > dp[i + 1][j][1]:
                    dp[i + 1][j] = [True, val, sett]

            sett = tab[:]
            sett[num(bot)] += 1
            #upd(i, j + 1, val, sett)
            if not dp[i][j + 1][0] or val > dp[i][j + 1][1]:
                dp[i][j + 1] = [True, val, sett]

            del dp[i][j][2]

    poss = [dp[i][n][1] for i in range(n + 1)]
        

    print(n - max(poss))