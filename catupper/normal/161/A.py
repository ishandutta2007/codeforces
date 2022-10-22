n,m,x,y=map(int,raw_input().split())
a=map(int,raw_input().split())
b=map(int,raw_input().split())
a.sort()
b.sort()

bb=0

res=[]

for aa in range(len(a)):
    while(bb<len(b) and b[bb]-y<=a[aa]):
        if(a[aa]-x<=b[bb]<=a[aa]+y):
            res+=[[aa+1,bb+1]]
            bb+=1
            break
        bb+=1
    

print len(res)
for x in res:
    print x[0],x[1]