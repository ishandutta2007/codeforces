import math
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    c = 0
    for i in range(n-1):
        a = min(arr[i], arr[i+1])
        b = max(arr[i], arr[i+1])
        if(b <= (2*a)):
            continue
        temp = a
        while(True):
            temp = 2*temp
            c += 1
            if(b > (2*temp)):
                continue
            else:
                break
    print(c)