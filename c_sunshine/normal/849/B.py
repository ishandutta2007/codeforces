n=int(input())
y=list(map(int,input().split()))
if n==2:
    print("Yes")
    exit
elif n==1:
    print("No")
    exit
def check(a,d):
    for i in range(0,n):
        a[i]-=i*d
    if len(set(a))==2:
        return True
    else:
        return False
if check(y.copy(),y[1]-y[0]):
    print("Yes")
    exit
elif check(y.copy(),y[2]-y[1]):
    print("Yes")
    exit
elif check(y.copy(),(y[2]-y[0])/2):
    print("Yes")
    exit
else:
    print("No")