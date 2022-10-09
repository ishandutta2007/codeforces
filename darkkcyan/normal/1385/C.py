for testcase in range(int(input())):
    n = int(input())
    a = list(reversed(list(map(int, input().split()))))
    
    i = 1
    while i < n and a[i - 1] <= a[i]:
        i += 1
    while i < n and a[i - 1] >= a[i]:
        i += 1
    print(n - i)