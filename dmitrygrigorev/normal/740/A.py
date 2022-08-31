n, a, b, c = list(map(int, input().split()))
if n % 4 == 0:
    print(0)
if n % 4 == 3:
    print(min(a, 3 * c, b + c))
if n % 4 == 2:
    print(min(b, 2 * a, 2 * c))
if n % 4 == 1:
    print(min(c, 3 * a, b + a))