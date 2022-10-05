n,x,d,m,f=int(input()),0,0,10**9+7,[1]
for i in range(1,9**6):f.append(f[-1]*i%m)
for z in map(int,input().split()):d+=f[z+x]*pow(f[x+1]*f[z-1],-1,m)*(z>0);x+=1
print(d%m)