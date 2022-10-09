for testcase in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    l, r = 0, n - 1
    while r - l + 1 >= 2:
        print(a[l], a[r], end = ' ')
        l += 1
        r -= 1
    if l == r:
        print(a[l])
    else:
        print()