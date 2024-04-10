a=input()
b=map(int,raw_input().split())
ma=max(b)
mi=min(b)
maind=b.index(ma)
miind=b[::-1].index(mi)
res=maind+miind
if(res>=a):res-=1
print res