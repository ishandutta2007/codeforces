c = map(int, raw_input().split(' '))

s = sum(c)

if (s % 5 != 0 or s == 0):
    print -1
else:
    print s / 5