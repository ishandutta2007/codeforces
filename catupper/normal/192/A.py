from math import sqrt
a=input()*2

x=1
while(x*(x+1)<a):
    b=a-x*(x+1)
    c=int(sqrt(b))

    if b==c*(c+1):
        print 'YES'
        exit()
    x+=1

print 'NO'