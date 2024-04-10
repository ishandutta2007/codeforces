mod = 10 ** 9 + 7
s = 0
two = 1
ans = 0
for c in raw_input():
    if c == 'a':
        s = (s + two) % mod
        two = (two + two) % mod
    else:
        ans = (ans + s) % mod
print ans