for _ in range(int(input())):
    n = int(input())
    d = dict()
    v = list()
    for i in range(n):
        v.append(input())
        d[v[-1]] = True
    ans = [0]*n
    for i in range(n):
        for j in range(1, len(v[i])):
            a = v[i][:j]
            b = v[i][j:]
            if(d.get(a) == None or d.get(b) == None):
                continue
            ans[i] = 1
    for i in ans:
        print(i, end = '')
    print()