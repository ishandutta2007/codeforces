n, q = map(int, input().split())
s = input()
d = list()
for i in range(26):
    d.append(list())
    d[i].append(0)
    temp = 0
    for j in range(n):
        if(ord(s[j])-97==i):
            temp += 1
        d[i].append(temp)
for i in range(q):
    l, r = map(int, input().split())
    ans = 0
    for j in range(26):
        ans += (d[j][r] - d[j][l-1])*(j+1)
    print(ans)