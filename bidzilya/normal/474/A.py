alp = ['qwertyuiop', 'asdfghjkl;', 'zxcvbnm,./']

direction = raw_input()
delta = 1

if (direction == 'R'):
    delta = -1

s = raw_input()
ans = ''
for c in s:
    for i in xrange(3):
        if (c in alp[i]):
            ans = ans + alp[i][alp[i].find(c) + delta]

print ans