n = int(raw_input())
x = [6, 8, 4, 2]
if not n:
    print 1
else:
    print x[n % 4]