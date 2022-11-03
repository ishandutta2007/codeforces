def get_ints():
    return map(int, raw_input().strip().split(' '))

def get_cost(p, t):
    return max(3 * p / 10, p - p / 250 * t)

a, b, c, d = get_ints()

a = get_cost(a, c)
b = get_cost(b, d)

if a > b:
    print 'Misha'
elif b > a:
    print 'Vasya'
else:
    print 'Tie'