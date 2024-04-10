n,m,k = list(map(int,input().split()))

l = list(map(int,input().split()))

out = 0
d = 0

while m > d:
    nex = l[d]
    page = (nex - d - 1)//k
    add = 1
    while d + add < m and (page * k) < l[d + add] - d  <= (page + 1) * k:
        add += 1
    d += add
    out += 1

print(out)