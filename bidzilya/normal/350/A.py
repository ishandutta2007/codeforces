def get_ints():
    return map(int, raw_input().strip().split(' '))


n, m = get_ints()
a = get_ints()
b = get_ints()
u = min(b)
ans = max(max(a), min(a) * 2)
if ans < u:
    print ans
else:
    print -1