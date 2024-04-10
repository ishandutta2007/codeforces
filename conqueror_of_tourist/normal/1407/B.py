from math import gcd
for v in [*open(0)][2::2]:
 l=list(map(int,v.split()));g=max(l);out = []
 while l:
  nex=max((gcd(g,l[i]),i)for i in range(len(l)))
  out+=[l.pop(nex[1])];g=nex[0]
 print(' '.join(map(str,out)))