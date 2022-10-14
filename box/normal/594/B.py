from math import *
def solve(dist,spd):
    z=floor(dist/(2*pi))
    ans=z*2*pi/spd
    dist=(dist-z*2*pi)/2
    st,cur=3/spd,0
    while st>=2e-7:
        if spd*(cur+st)+sin(spd*(cur+st))<=dist:
            cur+=st
        st/=2
    return ans+cur*2
n,rd,v=map(int,input().split())
for i in range(n):
    l,r=map(int,input().split())
    d=r-l
    print("%.10f"%solve(d/rd,v/rd))