def f(l):
    n = len(l)
    if n % 3 != 0 or any(len(set(x)) != 1 for x in l):
        return False
    l = [x[0] for x in l]
    d = [i for i in xrange(n) if i == 0 or l[i] != l[i-1]]
    return len(set(l)) == 3 and d == range(0, n, n / 3)
n, m = map(int, raw_input().split())
l = [raw_input() for i in xrange(n)]
print 'YES' if f(l) or f(map(list, zip(*l))) else 'NO'