for _ in xrange(input()):
    a, b = raw_input(), raw_input()
    i = 0
    for j in xrange(len(b)):
        if i < len(a) and b[j] == a[i]:
            i += 1
        elif i > 0 and b[j] == a[i - 1]:
            pass
        else:
            i = 0
            break
    print ["NO", "YES"][i == len(a)]