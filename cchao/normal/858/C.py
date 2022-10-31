f = lambda c: "aeiou ".find(c) == -1
a = []
for c in raw_input():
    if len(a) >= 2 and f(c) and f(a[-1]) and f(a[-2]) and not (c == a[-1] == a[-2]):
        a.append(' ')
    a.append(c)
print ''.join(a)