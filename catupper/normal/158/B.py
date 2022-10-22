input()
a=map(int,raw_input().split())

x=[a.count(b+1) for b in range(4)]

res=x[3]+x[2]
if(x[2]>x[0]):x[0]=0
else:x[0]-=x[2]
res+=x[1]/2+x[0]/4
k=x[0]%4+(x[1]%2)*2
res+=(k+3)/4
print res