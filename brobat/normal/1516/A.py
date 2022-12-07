for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    i = 0
    while(k>0):
        if(arr[i]>0):
            arr[i] -= 1
            k -= 1
            arr[-1] += 1
        else:
            i += 1
        if i==(n-1):
            break
    for x in arr:
        print(x, end=' ')