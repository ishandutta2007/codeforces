import string

def get_ints():
    return map(int, raw_input().strip().split(' '))

n = int(raw_input())
s = raw_input()

good = True
s = s.lower()
for c in string.ascii_lowercase:
    if not c in s:
        good = False

if good:
    print 'YES'
else:
    print 'NO'