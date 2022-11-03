def get_ints():
    return map(int, raw_input().strip().split(' '))

def get_sum_of_digits(x):
    res = 0
    while x > 0:
        res += (x % 10)
        x /= 10
    return res

a, b, c = get_ints()

ans = []
ans.sort()

for s in xrange(100):
    x = b * (s ** a) + c
    if x > 0 and x < 10 ** 9:
        if get_sum_of_digits(x) == s:
            ans.append(x)

print len(ans)
for i in ans:
    print i,