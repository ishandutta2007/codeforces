def func():
    arr = list(map(int,input().split()))
    n = arr[0]
    arr.pop(0)
    # Now arr has U,R,D,L
    if(max(arr)>n):
        return "NO"
    if(max(arr)<(n-1)):
        return "YES"
    if(min(arr)>1):
        return "YES"
    arr.append(arr[0])
    arr.insert(0,arr[-2])
    arr.append(arr[2])
    arr.append(arr[3])
    # print(arr)
    k = n-1
    for i in range(1,5):
        if(arr[i]==n and (arr[i-1]==0 or arr[i+1]==0)):
            return "NO"
        if((arr[i]==n and arr[i+1]==n) and (arr[i+2]==0 or arr[i+3]==0)):
            return "NO"
        if((arr[i]==n and arr[i+2]==n) and (arr[i+1]<2 or arr[i+3]<2)):
            return "NO"
        if((arr[i]==n and arr[i+1]==n and arr[i+2]==n) and arr[i+3]<2):
            return "NO"
        if(arr[i]==k and arr[i+1]==0 and arr[i+2]==k and arr[i+3]==1):
            return "NO"
        if((arr[i]==k) and (arr[i+1]==0 and arr[i+3]==0)):
            return "NO"
        if((arr[i]==k and arr[i+2]==k) and (arr[i+1]==0 and arr[i+3]==0)):
            return "NO"
        if((arr[i]==n and arr[i+2]==k) and (arr[i+1]+arr[i+3]==2)):
            return "NO"
    return "YES"


    

for _ in range(int(input())):
    print(func())