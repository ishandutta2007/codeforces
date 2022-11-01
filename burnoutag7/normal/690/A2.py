a=int(input())
if a%2==1:
    print(a//2)
    exit()
b=1
while b*2<=a:
    b*=2
print((a-b)//2)