for _ in range(int(input())):
    n = int(input())
    s = input()
    plus = [0]*n
    minus = [0]*n
    adj = [0]*n
    c = [0]*n
    if(s[0] == '+'):
        plus[0] = 1
    else:
        minus[0] = 1
    for i in range(1, n):
        plus[i] = plus[i - 1]
        minus[i] = minus[i - 1]
        if(s[i] == '+'):
            plus[i] += 1
        else:
            minus[i] += 1
    cnt = 0
    if(minus[0] == 1):
        cnt = 1
    c[0] = cnt
    for i in range(1, n):
        adj[i] = adj[i - 1]
        if(s[i] == '+'):
            cnt = 0
            c[i] = cnt
            continue
        cnt += 1
        c[i] = cnt
        if(cnt % 2 == 0 and cnt > 0):
            adj[i] += 1
    # print(adj) # Problem in case of ---, what if we consider substr starting with index 1??
    # print(plus)
    # print(minus)
    # print(adj)
    ans = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            # Check for arr[i .... j]
            o = plus[j] - (0 if i == 0 else plus[i - 1])
            z = minus[j] - (0 if i == 0 else minus[i - 1])
            a = adj[j] - (0 if i == 0 else adj[i - 1])
            if(o <= z and (z - o) % 3 == 0 and (z - o)//3 <= a):
                ans += 1
                # print(i, j)
    print(ans)