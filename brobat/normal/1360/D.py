import math

def func(n) :
     
    # Note that this loop runs till square root
    i = 1
    arr = []
    while i <= math.sqrt(n):
         
        if (n % i == 0) :
             
            # If divisors are equal, print only one
            if (n / i == i) :
                arr.append(i)
            else :
                # Otherwise print both
                arr.append(i)
                arr.append(n//i)
        i = i + 1
    return arr

for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = func(n)
    ans = 1
    arr.sort()
    for i in range(len(arr)-1):
        if(arr[i+1]>k):
            break
        ans = arr[i+1]
    print(n//ans)