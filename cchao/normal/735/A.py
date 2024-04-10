(n, k) = tuple(int(x) for x in raw_input().split())
s = raw_input()
t, g = s.find('T'), s.find('G')
if t % k != g % k:
    print 'NO'
else:
    if t > g:
        t, g = g, t
    print 'YES' if s[t:g+1:k].find('#') == -1 else 'NO'