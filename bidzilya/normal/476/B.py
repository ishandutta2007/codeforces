def inc_val(d, key, value):
    if key in d:
        d[key] += value
    else:
        d[key] = value

s1 = raw_input()
s2 = raw_input()

sum1 = 0
for c in s1:
    sum1 += (1 if c == '+' else -1)

d = {0: 1.0}
for c in s2:
    nd = {}
    for key, value in d.items():
        if c == '+':
            inc_val(nd, key + 1, value)
        elif c == '-':
            inc_val(nd, key - 1, value)
        else:
            inc_val(nd, key + 1, value * 0.5)
            inc_val(nd, key - 1, value * 0.5)
    d = nd

if sum1 in d:
    print d[sum1]
else:
    print 0.0