for l in [*open(0)][1:]:
 n,x,y = map(int, l.split());p=[]
 for i in range(1,n):
  if(y-x)%i==0:
   s=(y-x)//i;a=x%s
   if a==0:a=s
   p.append((max(a+s*n-s,y),s))
 a,b=min(p)
 print(*range(a-b*n+b,a+1,b))