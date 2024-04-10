z=input;w=lambda:map(int,z().split());u=int(z())+1
while u:=u-1:
 z();_,m=w();d=l=0
 for x,y in sorted([*w()][::-1]for _ in [8]*m):
  if abs(d:=d+(x+y)%2*2-1)>1 or l==x and d:d=m
  l=x
 print('no'if d else'yes')