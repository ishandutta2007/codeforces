f = lambda c: "aeiou ".find(c) == -1

s = raw_input()

a = []

n = len(s)

for c in s:
    if len(a) < 2:
        a.append(c)
    elif f(c) and f(a[-1]) and f(a[-2]):
        if c == a[-1] == a[-2]:
            a.append(c)
        else:
            a.append(' ')
            a.append(c)
    else:
        a.append(c)

print ''.join(a)