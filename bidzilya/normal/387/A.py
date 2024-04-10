def get_ints():
    return map(int, raw_input().strip().split(' '))

def get_time():
    a, b = map(int, raw_input().split(':'))
    return a * 60 + b

def show_time(t):
    s = ''
    h = t / 60
    m = t % 60
    if h < 10:
        s += '0'
    s += str(h)
    s += ':'
    if m < 10:
        s += '0'
    s += str(m)
    print s

t1 = get_time()
t2 = get_time()

t1 -= t2
if t1 < 0:
    t1 += 60 * 24

show_time(t1)