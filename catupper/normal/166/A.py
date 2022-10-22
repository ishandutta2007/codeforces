a,b=map(int,raw_input().split())

t=[]
for x in range(a):
    x,y=map(int,raw_input().split())
    t+=[[x,-y]]

t.sort()
t=t[::-1]
print t.count(t[b-1])