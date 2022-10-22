a = raw_input()
if '0' not in a:
    print a[1:]
else:
    n = a.index('0')
    print a[:n] + a[n + 1:]