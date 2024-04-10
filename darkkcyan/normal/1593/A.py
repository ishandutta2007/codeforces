for testcase in range(int(input())):
    a, b, c = map(int, input().split())
    x = max(0, max(b, c) + 1 - a)
    y = max(0, max(a, c) + 1 - b)
    z = max(0, max(b, a) + 1 - c)
    print(x, y, z)