t = int(input())
ma = []
i = 1
while i<=t:
    m = int(input())
    s = (m*(m+1))//2
    k = 1
    while k<=m:
        s = s - 2*k
        k = k * 2
    ma.append(s)
    i = i+1
i = 1
while i<=t:
    print(ma[i-1])
    i = i+1