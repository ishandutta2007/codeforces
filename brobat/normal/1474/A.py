def func():
    n = int(input())
    ss = input()
    b = []
    for i in range(n):
        b.append(int(ss[i]))
    a = [1]
    for i in range(1,n):
        if (b[i]==1 and b[i-1]==1) or (b[i]==0 and b[i-1]==0):
            if a[i-1]==1:
                a.append(0)
            else:
                a.append(1)
        elif b[i]==1 and b[i-1]==0:
            a.append(1)
        elif b[i]==0 and b[i-1]==1:
            a.append(a[i-1])
    for i in range(n):
        print(a[i],end='')
    print()



T = int(input())
for _ in range(T):
    func()