from collections import*
n=int(input())
d=defaultdict(int)
for i in range(0,n):
 l,r=map(int,input().split());d[l]+=1;d[r+1]-=1;            
s=p=0
f=[0]*(n+1)
for k in sorted(d):               
 f[s]+=k-p;s+=d[k];p=k
print(*f[1:])