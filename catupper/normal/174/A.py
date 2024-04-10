from __future__ import division
a,b=map(int,raw_input().split())
c=map(int,raw_input().split())

t=max(c)
k=map(lambda x:t-x,c)
su=sum(k)
if su>b:
    print -1
    exit()

lili=(b-su)/len(c)
for x in k:
    print x+lili