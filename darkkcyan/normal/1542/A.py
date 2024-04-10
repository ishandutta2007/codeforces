for testcase in range(int(input())):
    n = int(input())
    par = sum(int(i) % 2 for i in input().split())
    print("Yes" if par == n else "No")