n = int(input())

test = 2
out = 1
while test * test <= n:
    p = 0
    while n % test == 0:
        n //= test
        p += 1

    if p >= 1:
        out = test
        break

    test += 1

if out == 1 and n > 1:
    print(n)
elif out > 1 and n == 1:
    print(out)
else:
    print(1)