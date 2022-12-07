l, r, k = map(int, input().split())
arr = [1]
for i in range(100000):
    arr.append(arr[-1]*k)
    if(arr[-1]>r):
        break
count = 0
for i in range(len(arr)):
    if(arr[i]>=l and arr[i] <= r):
        print(arr[i], end=' ')
        count += 1
if(count==0):
    print(-1)