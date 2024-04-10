s = input()
m = s.split(' ')
n = int(m[0])
t = int(m[1])
small = 1
i = 1
while i<=n-1:
    small = small*10
    i = i + 1
big = small*10-1
ost = small % t
if ost == 0:
    f2 = small
else:
    f2 = small + (t- ost)
if f2<=big:
    print(f2)
else:
    print(-1)