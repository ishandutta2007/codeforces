t = int(input())
for _ in range(t):
    A, B = map(int, input().split())
    b = -1
    B += 1
    while B:
        b += 1
        B //= 10
    print(A*b)