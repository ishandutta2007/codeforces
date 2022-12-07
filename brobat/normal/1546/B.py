for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = list()
    for _ in range(n):
        arr.append(input())
    grr = list()
    for _ in range(n-1):
        grr.append(input())
    a = list()
    for i in range(m):
        temp = 0
        for j in range(n):
            temp += ord(arr[j][i])
        a.append(temp)
    b = list()
    for i in range(m):
        temp = 0
        for j in range(n-1):
            temp += ord(grr[j][i])
        b.append(temp)
    c = list()
    for i in range(m):
        c.append(a[i]-b[i])
    s = ""
    for i in range(m):
        s += chr(c[i])
    print(s)