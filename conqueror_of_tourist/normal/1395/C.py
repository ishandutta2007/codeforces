f=input;f();g=lambda:[*map(int,f().split())];a=g();b=g()
for x in range(512):
 r=1
 for v in a:r&=any(v&j|x==x for j in b)
 if r:print(x);break