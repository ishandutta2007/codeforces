from sys import stdin, exit
n = int(stdin.readline())

for i in range(n):
    a, b, c, d = map(int, stdin.readline().split())
    swapped = False
    if a > c:
        swapped = True
        a, c = c, a
        b, d = d, b
    x = a
    y = d
    if swapped:
        x, y = y, x
    print(x, y)