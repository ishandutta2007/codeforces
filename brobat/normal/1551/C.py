def func(a, i):
    return a[i-1] + a[i]

for _ in range(int(input())):
    n = int(input())
    # a,b,c,d,e = list()
    a = list()
    b = list()
    c = list()
    d = list()
    e = list()
    for _ in range(n):
        s = input()
        temp = list()
        z = len(s)
        for i in range(z):
            temp.append(s[i])
        a.append(temp.count('a')*2 - z)
        b.append(temp.count('b')*2 - z)
        c.append(temp.count('c')*2 - z)
        d.append(temp.count('d')*2 - z)
        e.append(temp.count('e')*2 - z)
    # print(a, b, c, d, e)
    a.sort(reverse=True)
    b.sort(reverse=True)
    c.sort(reverse=True)
    d.sort(reverse=True)
    e.sort(reverse=True)
    for i in range(1, n):
        a[i] = func(a, i)
        b[i] = func(b, i)
        c[i] = func(c, i)
        d[i] = func(d, i)
        e[i] = func(e, i)
    # print(a, b, c, d, e)
    a.reverse()
    b.reverse()
    c.reverse()
    d.reverse()
    e.reverse()
    ans = 10000000000
    for i in range(n):
        if(a[i]>0 or b[i]>0 or c[i]>0 or d[i]>0 or e[i]>0):
            ans = i
            break
    print(max(n - ans, 0))