n, m, x, y, dx, dy = list(map(int, input().split()))


def trivial():
    if dx == 0:
        if x != 0 and x != n:
            print(-1)
        else:
            if dy == 1:
                print(x, m)
            else:
                print(x, 0)
        exit(0)
    if dy == 0:
        if y != 0 and y != m:
            print(-1)
        else:
            if dx == 1:
                print(n, y)
            else:
                print(0, y)
        exit(0)


def write(ans, x, y, n, m, dx, dy):
    x = (ans + x) // n;
    y = (ans + y) // m;
    if (x % 2 == 0):
        x = 0
    else:
        x = n
    if (y % 2 == 0):
        y = 0
    else:
        y = m;
    if (dx == -1):
        x = n - x
    if (dy == -1):
        y = m - y
    print(x, y)
    exit(0)


def euclid(x, y):
    if (x == 0):
        return y, 0, 1
    g, qq, ww = euclid(y % x, x)
    q = ww - (y // x) * qq
    w = qq
    return g, q, w


trivial()
if (dx == -1):
    x = n - x
if (dy == -1):
    y = m - y
gcd, q, w = euclid(n, m)
w *= -1;
diff = x - y;
if (diff % gcd):
    print(-1)
    exit(0)
q *= (diff // gcd)
w *= (diff // gcd)
ans = n * q - x
pl = n * m // gcd
ans %= pl
if (ans < 0):
    ans += pl
write(ans, x, y, n, m, dx, dy)