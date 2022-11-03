def get_ints():
    return map(int, raw_input().strip().split(' '))

n, k = get_ints()

ans = [0 for i in xrange(n)]
ans[0] = 1
dx = 1
s = n - 1
for i in xrange(1, n):
    if k == 1:
        ans[i] = ans[i - 1] + dx
    else:
        k -= 1
        ans[i] = ans[i - 1] + dx * s
        s -= 1
        dx *= -1
        
for i in xrange(n):
    print ans[i],