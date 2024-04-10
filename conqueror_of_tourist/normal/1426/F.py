input();o=a=b=0;v=1;M=10**9+7
for c in input():
 if c=='a':a+=v
 elif c=='b':b+=a
 elif c=='c':o+=b
 else:a,b,o,v=(3*a+v)%M,(3*b+a)%M,(3*o+b)%M,(3*v)%M
print(o%M)