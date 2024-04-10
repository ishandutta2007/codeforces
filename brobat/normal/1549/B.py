for _ in range(int(input())):
    n = int(input())
    s = input()
    m = input()
    enemy = [0]
    for i in range(n):
        enemy.append(int(s[i]))
    enemy.append(0)
    me = []
    for i in range(n):
        me.append(int(m[i]))
    ans = 0
    for i in range(n):
        if(me[i]==1):
            if(enemy[i]==1):
                ans += 1
                enemy[i] = 0
            elif(enemy[i+1]==0):
                ans += 1
            elif(enemy[i+2]==1):
                ans += 1
                enemy[i+2] = 0
    print(ans)