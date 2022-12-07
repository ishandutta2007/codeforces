for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        if(arr[i]!=(i+1)):
            ans = 1
            break
    if(ans==0):
        print(0)
    else:
        if(arr[0]==n and arr[n-1]==1):
            print(3)
        elif(arr[0]==1 or arr[n-1]==n):
            print(1)
        else:
            print(2)