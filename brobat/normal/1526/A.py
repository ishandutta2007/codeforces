for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    while(arr):
        print(arr[0], end=' ')
        print(arr[-1], end=' ')
        arr.pop()
        arr.pop(0)
    print()