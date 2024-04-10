le = int(input())
s = input()
l = [[0,0]]
curr = [0,0]
for i in range(le):
    c = s[i]
    if c == 'U':
        curr[1] += 1
    elif c == 'R':
        curr[0] += 1
    elif c == 'L':
        curr[0] -= 1
    else:
        curr[1] -= 1
    l.append(curr[:])
l2 = []
for i in range(len(l)):
    if not(l[i] in l2):
        l2.append(l[i][:])
l3 = [0]*len(l2)

for i in range(len(l2)):
    for j in range(len(l)-1,-1,-1):
        if l2[i] == l[j]:
            l3[i]+=1
            l.pop(j)
out = 0
for val in l3:
    out += (val)*(val-1)//2
print(out)