n = int(raw_input())

d = map(int, raw_input().split(' '))

s, t = map(int, raw_input().split(' '))

if s > t:
    s, t = t, s
s -= 1
t -= 1

all_d = sum(d)

cur_d = 0
for i in xrange(s, t):
    cur_d += d[i]

print min(cur_d, all_d - cur_d)