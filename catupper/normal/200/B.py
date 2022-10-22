from __future__ import division
a=input()
t=map(int,raw_input().split())
t=map(lambda x:x/a,t)
print sum(t)