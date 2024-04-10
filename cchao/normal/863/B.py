n, a = input() * 2, sorted(map(int, raw_input().split()))
def f(a):
    return sum(a[i + 1] - a[i] for i in xrange(0, len(a), 2))
print min(f(a[0:i] + a[i+1:j] + a[j+1:n]) for j in xrange(n) for i in xrange(j))