a,b=map(int,raw_input().split())
c=map(int,raw_input().split())

c.sort()
c=c[c.count(0):][::-1]

if(len(c)<b):print len(c)
else:
    x=c[b-1]
    res=0
    for k in c:
        if(k<x):break
        res+=1
    print res