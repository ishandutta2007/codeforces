R=lambda:map(int,input().split())
t,=R()
while t:
 t-=1;R();a=[[],[]];s=i=0
 for x,y in zip(R(),R()):i+=1;d=y-x;s+=d;a[d>0]+=[i]*abs(d)
 print(*s and[-1]or[len(a[0])]+[f'{i} {j}'for i,j in zip(*a)])