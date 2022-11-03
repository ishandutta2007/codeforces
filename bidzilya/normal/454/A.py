n = int(raw_input())

for i in xrange(n / 2):
    j = 2 * i + 1
    k = (n - j) / 2
    print ('*' * k) + ('D' * j) + ('*' * k)

for i in xrange(n / 2, n):
    j = n - 2 * (i - n / 2)
    k = (n - j) / 2
    print ('*' * k) + ('D' * j) + ('*' * k)