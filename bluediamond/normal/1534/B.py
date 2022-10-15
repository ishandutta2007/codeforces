for s in[*open(0)][2::2]:
 r=c=x=0
 for y in map(int,s.split()+[0]):t=abs(d:=y-x);r+=max(t-c,c:=t+d>>1);x=y
 print(r)