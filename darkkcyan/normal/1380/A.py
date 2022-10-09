for testcase in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = - 1
    for i in range(n - 2):
        if a[i] < a[i + 1] and a[i + 1] > a[i + 2]:
            ans = i
            break
    if ans == -1:
        print("NO")
        continue
    print("YES")
    print(i + 1, i + 2, i + 3)