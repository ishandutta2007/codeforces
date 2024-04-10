a,b=map(int,raw_input().split())
names=[]
friends=[]
for x in range(a):
    c,d,e=raw_input().split()
    e=int(e)
    names+=[[c,d,e]]
    
for t in names:
    p=[t[0],t[1]]
    p.sort()
    if p in friends:continue
    for x in names:
        if x[0]==t[1] and x[1]==t[0] and 0<t[2]-x[2]<=b:
            friends+=[p]
            break

print len(friends)
for x in friends:
    print x[0],x[1]