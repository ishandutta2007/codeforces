for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    if(sum(arr)%n!=0):
        print(-1)
    else:
        ans = 0
        t = sum(arr)//n
        for i in range(n):
            if(arr[i]>t):
                ans+=1
        print(ans)