for _ in range(int(input())):
    a, b = map(int, input().split())
    print(a * (len(str(b + 1)) - 1))