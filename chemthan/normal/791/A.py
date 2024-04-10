a, b = list(int(x) for x in input().split())
for i in range(1, 10):
    a = a * 3
    b = b * 2
    if a > b:
        print(i)
        exit(0)

exit(0)