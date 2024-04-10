n = int(raw_input())
a = raw_input()
c = 0
while c < n and a[c] == '1':
    c += 1

if c == n:
    print n
else:
    print c + 1