n, m, a, b = map(int, raw_input().split(' '))
if m * a < b:
    print n * a
else:
    print (n / m) * b + min((n % m) * a, b)