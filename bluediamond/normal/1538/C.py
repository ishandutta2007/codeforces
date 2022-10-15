R=lambda:map(int,input().split())
t,=R()
while t:
 t-=1;n,l,r=R();a=sorted(R());i=j=q=0
 while i<n:
  n-=1
  while i<n and a[i]+a[n]<l:i+=1
  while j<n and a[j]+a[n]<=r:j+=1
  q+=min(j,n)-i
 print(q)