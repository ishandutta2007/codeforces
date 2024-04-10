import sys
input = sys.stdin.readline

n = int(input())

l = []
ins = []

for i in range(n):
    s = input().split()
    if len(s) == 2:
        if s[0] == 'IN':
            l.append([s[0],int(s[1])])
            ins.append(i)
        else:
            l.append([s[0],int(s[1])-1])
        
    else:
        l.append([s[0],int(s[1])-1,int(s[2])-1])

vals = [-1]*n

q = [[0,0]]

while q:
    test = q.pop()
    now = l[test[0]]
    
    if now[0] == 'IN':
        vals[test[0]] = now[1]
    else:
        if test[1] == 0:
            q.append([test[0],1])
            for i in now[1:]:
                q.append([i,0])
        else:
            if now[0] == 'AND':
                vals[test[0]] = vals[now[1]]&vals[now[2]]
            elif now [0] == 'OR':
                vals[test[0]] = vals[now[1]]|vals[now[2]]
            elif now[0] == 'NOT':
                vals[test[0]] = 1-vals[now[1]]
            else:
                vals[test[0]] = vals[now[1]]^vals[now[2]]

out = vals[0]


changeMat = [0]*n

q = [0]
while q:
    test = q.pop()
    changeMat[test] = 1
    now = l[test]
    if now[0] == 'NOT':
        q.append(now[1])
    if now[0] == 'XOR':
        q.append(now[1])
        q.append(now[2])
    if now[0] == 'AND':
        if vals[now[1]]:
            q.append(now[2])
        if vals[now[2]]:
            q.append(now[1])
    if now[0] == 'OR':
        if vals[now[1]] == 0:
            q.append(now[2])
        if vals[now[2]] == 0:
            q.append(now[1])

for i in ins:
    print(changeMat[i]^out,end='')