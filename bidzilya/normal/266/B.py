def NextS(s):
    ns = ''
    i = 0
    while (i < len(s)):
        if s[i] == 'G':
            ns = ns + 'G'
            i += 1
        else:
            if (i + 1 < len(s)):
                if (s[i + 1] == 'G'):
                    ns = ns + 'GB'
                    i += 2
                else:
                    ns = ns + 'B'
                    i += 1
            else:
                ns = ns + 'B'
                i += 1
    return ns

n, t = map(int, raw_input().split(' '))
s = raw_input()

for itr in xrange(t):
    s = NextS(s)

print s