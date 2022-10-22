from __future__ import division

n,k=map(int,raw_input().split())

stools=[]
pencils=[]

carts=[[] for x in range(k)]
incarts=[[] for x in range(k)]
waribiki=[0 for x in range(k)]
for x in range(n):
    a,b=map(int,raw_input().split())
    if(b==1):
        stools+=[[a,x+1]]
    else:
        pencils+=[[a,x+1]]
        
stools.sort()
stools=stools[::-1]

sst=stools[:k]
sstt=stools[k:]

for x in range(len(sst)):
    carts[x]+=[sst[x][0]]
    incarts[x]+=[sst[x][1]]
    waribiki[x]=1
carts[-1]+=map(lambda x:x[0],sstt)
incarts[-1]+=map(lambda x:x[1],sstt)
n=-1
try:
    while(len(carts[n])==0):
        carts[n]+=[pencils[-1][0]]
        incarts[n]+=[pencils.pop()[1]]
        n-=1
except:pass

carts[-1]+=map(lambda x:x[0],pencils)
incarts[-1]+=map(lambda x:x[1],pencils)

res=0
for x in range(len(carts)):
    res+=sum(carts[x])
    if(waribiki[x]):
        res-=min(carts[x])/2

print str(int(res))+'.'+str(int(res*10)%10)
for x in incarts:
    print str(len(x))+' '+' '.join(map(str,x))