def f(d,i,j):
 if i<j:k=a.index(max(a[i:j]),i,j);r[k]=d;d+=1;f(d,i,k);f(d,k+1,j)
for s in[*open(0)][2::2]:a=*map(int,s.split()),;n=len(a);r=[0]*n;f(0,0,n);print(*r)