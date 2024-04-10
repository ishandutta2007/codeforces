count = 0
n, q = map(int,input().split())
arr = list(map(int,input().split()))
for i in range(n):
    if(arr[i]==1):
        count += 1
for i in range(q):
    t,x = map(int,input().split())
    if(t==2):
        if(x<=count):
            print(1)
        else:
            print(0)
    if(t==1):
        arr[x-1] = 1 - arr[x-1]
        if(arr[x-1]==0):
            count -= 1
        else:
            count += 1