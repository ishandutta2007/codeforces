for l in [*open(0)][1:]:
 a,b,x,y,n=map(int,l.split());p=[]
 for q,w,e,r in ((a,b,x,y),(b,a,y,x)):
  i=min(q-e,n);j=min(w-r,n-i);p.append((q-i)*(w-j))
 print(min(p))