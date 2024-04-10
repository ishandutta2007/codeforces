a=input()
b=input()
c=0
d=0
for i in b:
    c+=1
    if i=='n':
        d+=1
c-=d*3
c//=4
for i in range(0,d):
    print(1,end=' ')
for i in range(0,c):
    print(0)