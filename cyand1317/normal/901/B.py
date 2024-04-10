n = int(input())

def print_poly(a):
    print(len(a) - 1)
    print(' '.join(map(str, a)))

def shift_add(a, mul, b):
    c = [0] * (len(a) + 1)
    for i in range(len(a)): c[i + 1] = a[i] * mul
    for i in range(len(b)): c[i] += b[i]
    return c

a = [0, 1]
b = [1]

for i in range(n - 1):
    c = shift_add(a, 1, b)
    if max(c) <= 1 and min(c) >= -1:
        a, b = c, a
    else:
        c = shift_add(a, -1, b)
        if max(c) <= 1 and min(c) >= -1:
            a, b = c, a
        else:
            print('> <')

if a[-1] == -1:
    a = list(map(lambda x: -x, a))
if b[-1] == -1:
    b = list(map(lambda x: -x, b))

print_poly(a)
print_poly(b)