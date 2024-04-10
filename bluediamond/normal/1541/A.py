for s in[*open(0)][1:]:
 n=int(s);i=n%2+3;print(2,n%2*'3',1)
 while i<n:print(i+1,i);i+=2