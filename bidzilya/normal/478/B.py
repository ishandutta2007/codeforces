def get_ints():
    return map(int, raw_input().split(' '))

def C2(n):
    return n * (n - 1) / 2

def get_kmin(n, m):
    k = n / m
    t = n % m
    return (m - t) * C2(k) + t * C2(k + 1)

def get_kmax(n, m):
    n -= m
    return C2(n + 1)

n, m = get_ints()

print get_kmin(n, m), get_kmax(n, m)