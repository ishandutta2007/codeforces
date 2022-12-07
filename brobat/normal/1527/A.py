arr = [1]
for i in range(30):
    arr.append(arr[-1]*2)
for _ in range(int(input())):
    n = int(input())
    for i in range(31):
        if(arr[i]>n):
            print(arr[i-1] - 1)
            break