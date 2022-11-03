n, m = map(int, raw_input().split(' '))
a = map(int, raw_input(). split(' '))

pos = 1
ans = 0
for x in a:
    if x >= pos:
        ans += x - pos
    else:
        ans += n - pos + x
    pos = x
print ans