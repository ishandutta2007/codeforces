t, a, b = map(int, input().split())

def gcd(a, b):
    if (b == 0):
        return a
    else:
        return gcd(b, a%b)

x, d = gcd(a, b), min(a, b)
lcm = (a*b)//x
answer = t//lcm*d + min(d, t%lcm + 1) - 1
gcd_of = gcd(answer, t)

print(answer // gcd_of, "/", t // gcd_of, sep = "")