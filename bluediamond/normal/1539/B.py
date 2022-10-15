n,s,*a=open(0);b=[0]
for x in s:b+=b[-1]+ord(x)-96,
for s in a:l,r=map(int,s.split());print(b[r]-b[l-1])