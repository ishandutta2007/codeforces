n = int(input())
m = int(input())

if n >= 100:
    print m
else:
    r = 1
    for _ in range(n):
        r *= 2
    print m % r