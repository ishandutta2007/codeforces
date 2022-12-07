for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list()
    if(sum(a)!=sum(b)):
        print(-1)
    else:
        c = list()
        for i in range(n):
            c.append([a[i] - b[i], i])
        c.sort()
        # print(c)
        d = list()
        while(len(c)>0):
            if(c[0][0]==0):
                c.pop(0)
                continue
            if(c[-1][0]==0):
                c.pop()
                continue
            c[0][0] += 1
            c[-1][0] -= 1
            d.append([c[-1][1]+1, c[0][1]+1])
        print(len(d))
        for i in range(len(d)):
            print(f"{d[i][0]} {d[i][1]}")