xx, yy, zz = map(int,raw_input().split())
x, y, z = map(int,raw_input().split())
a = map(int,raw_input().split())
ans = 0

if(xx <0):ans += a[4]
if(yy <0):ans += a[0]
if(zz <0):ans += a[2]
if(xx >x):ans += a[5]
if(yy >y):ans += a[1]
if(zz >z):ans += a[3]

print ans