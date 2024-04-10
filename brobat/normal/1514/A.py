import math

for _ in range(int(input())):
    n = int(input())
    x = 0
    arr = list(map(int, input().split()))
    for i in range(n):
        if(math.sqrt(arr[i])!=int(math.sqrt(arr[i]))):
            print("YES")
            x = 1
            break
    if(not x):
        print("NO")