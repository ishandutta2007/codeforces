def func(x, y, arr, n):
    t = y + 1
    t = min(t, x + 1 + n - y)
    t = min(t, n - x)
    print(t)

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    x = arr.index(min(arr))
    y = arr.index(max(arr))
    if(x>y):
        func(y, x, arr, n)
    else:
        func(x, y, arr, n)