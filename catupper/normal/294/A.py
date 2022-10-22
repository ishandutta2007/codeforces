a = input()
b = map(int, raw_input().split())
b = [0] + b + [0]

for x in xrange(input()):
    p, q = map(int, raw_input().split())
    b[p - 1] += q - 1
    b[p + 1] += b[p] - q
    b[p] = 0

for x in xrange(a):
    print b[x + 1]