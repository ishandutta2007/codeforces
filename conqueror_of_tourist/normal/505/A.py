def ptest(l):
    m = l[:]
    m.reverse()
    if m == l:
        return True
    return False


a = input()
a = list(a)
lett = set(a)
done = False
for x in range(len(a)+1):
    b = a[:]
    for t in lett:
        c = b[:x] + [t] + b[x:]
        c.reverse()
        if ptest(c):
            done = True
            print(''.join(c))
            break
    if done:
        break
if not(done):
    print("NA")