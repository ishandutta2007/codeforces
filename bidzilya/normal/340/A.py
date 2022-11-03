def get_ints():
    return map(int, raw_input().strip().split(' '))

def gcd(a, b):
    while a > 0 and b > 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b

def lcm(a, b):
    return a / gcd(a, b) * b

x, y, a, b = get_ints()

l = lcm(x, y)

print (b / l) - ((a - 1) / l)