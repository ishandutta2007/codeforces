def get_ints():
    return map(int, raw_input().strip().split(' '))

def gcd(a, b):
    while a > 0 and b > 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b

l, r = get_ints()

ans = []
for a in range(l, r + 1):
    for b in range(a + 1, r + 1):
        for c in range(b + 1, r + 1):
            if gcd(a, b) == 1 and gcd(b, c) == 1 and \
               gcd(a, c) != 1:
                ans.append([a, b, c])

if len(ans) == 0:
    print -1
else:
    print ans[0][0], ans[0][1], ans[0][2]