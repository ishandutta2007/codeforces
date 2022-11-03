def get_ints():
    return map(int, raw_input().strip().split(' '))

def get_counter(s):
    res = [0] * 26
    for c in s:
        res[ord(c) - ord('A')] += 1
    return res

l, r = raw_input().split('|')
s = raw_input()

for c in s:
    if len(l) < len(r):
        l += c
    else:
        r += c

if len(l) != len(r):
    print 'Impossible'
else:
    print l + '|' + r