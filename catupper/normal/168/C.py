from __future__ import division
from math import sqrt
a,b,c=map(int,raw_input().split())
hayaist=0
for x in range(a):
    p,q=map(int,raw_input().split())
    x=(c-(q*q/(2*b)))/q
    y=p+(q/b)+x
    if(x<0):
        y=p+sqrt(2*c/b)
    if(hayaist<=y):hayaist=y
    print "%.10f"%hayaist