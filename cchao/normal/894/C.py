n, a = input(), raw_input().split()
if any(int(x) % int(a[0]) for x in a): print -1
else: print n*2, ' '.join(x + ' ' + a[0] for x in a)