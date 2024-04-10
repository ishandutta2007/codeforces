n = int(input())
for i in range(-n // 2 + 1, n // 2 + 1):
    print("*" * abs(i) + "D" * (n - abs(2 * i)) + "*" * abs(i))