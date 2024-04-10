s = raw_input()
d = {}
for i in s:
    d[i] = 1
if len(d) % 2 == 0:
    print 'CHAT WITH HER!'
else:
    print 'IGNORE HIM!'