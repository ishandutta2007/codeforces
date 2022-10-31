n = input()
a = map(int, raw_input().split())

if n % 2 == 1:
    print sum(map(abs, a))
    quit()

neg = sum(x < 0 for x in a) % 2

a = sorted(map(abs, a))

if neg == 1:
    a[0] = -a[0]

print sum(a)