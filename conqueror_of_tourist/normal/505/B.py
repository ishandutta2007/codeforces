n,m = input().split(' ')
l = []
for x in range(int(m)):
    l.append(list(range(int(n))))
for x in range(int(m)):
    p = input().split(' ')
    newl = l[int(p[2])-1]
    a,i = max(newl[int(p[0])-1],newl[int(p[1])-1]),min(newl[int(p[0])-1],newl[int(p[1])-1])
    for y in range(len(newl)):
        if newl[y] == a:
            newl[y] = i
    l[int(p[2])-1] = newl
q = int(input())
put = []
for x in range(q):
    out = 0
    a,b = input().split(' ')
    for n in l:
        if n[int(a)-1] == n[int(b)-1]:
            out += 1
    put.append(out)
for x in put:
    print(x)