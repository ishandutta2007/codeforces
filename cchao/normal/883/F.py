def f():
    s = raw_input()
    s = s.replace('u', 'oo')
    s = s.replace('oo', 'u')
    while 'kh' in s:
        s = s.replace('kh', 'h')
    return s

n = input()
print len(set(f() for i in xrange(n)))