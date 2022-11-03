def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())

a = get_ints()

ans = ''
for i in xrange(n - 1):
    ans += 'PRL' * a[i]
    ans += 'R'
    
ans += 'PLR' * a[n - 1]

print ans