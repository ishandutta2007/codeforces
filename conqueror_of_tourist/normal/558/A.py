num = int(input())
neg = []
pos = []
for x in range(num):
    coord, app = map(int,input().split(' '))
    if coord < 0:
        neg.append([-1*coord,app])
    else:
        pos.append([coord,app])
pos.sort()
neg.sort()
if len(neg)<len(pos):
    a = neg
    b = pos[:len(neg)+1]
elif len(pos)<len(neg):
    a = pos
    b = neg[:len(pos)+1]
else:
    a = pos
    b = neg
tot = 0
for i in a:
    tot += i[1]
for i in b:
    tot+= i[1]
print(tot)