n = int(input())
arr = list(map(int, input().split()))
ans = 0
while(True):
    l = max(arr)
    max_index = arr.index(l)
    if(max_index==0):
        zz = False
        for i in range(1,n):
            if(arr[i]==arr[0]):
                print(ans + 1)
                zz = True
                break
        if(zz==False):
            print(ans)
        break
    arr[0] += 1
    arr[max_index] -= 1
    ans += 1