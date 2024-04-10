ntest = int(input())
for testcase in range(ntest):
    x, y, n = map(int, input().split())
    t = (n - y) // x * x + y
    print(t)