a,b=map(int,raw_input().split())

def n(x):
    res=0
    while(x!=0 and res<a):
        res+=x
        x/=b
    return res>=a

up,down=10**9,1

while(True):
    mid=(up+down)/2
    if(n(mid) and not n(mid-1)):
        print mid
        break
    if(n(mid)):
        up=mid-1
    else:
        down=mid+1