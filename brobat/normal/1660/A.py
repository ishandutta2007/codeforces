for _ in range(int(input())):
    a, b = map(int, input().split())
    print(1 if a == 0 else a + 2*b + 1)