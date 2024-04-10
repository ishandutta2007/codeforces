a,b=map(int,raw_input().split())
c=map(int,raw_input().split())
res=0
if b not in c:
    c+=[b]
    res+=1
c.sort()
p=c.index(b)
l=len(c)
q=l-c[::-1].index(b)-1

if(p<=(l+1)/2-1<=q):
    print res
    exit()

if((l+1)/2-1<p):
    print res+p*2+1-l
    exit()

else:
    t=l-2-q
    print res+t-q
    exit()