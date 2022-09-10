n = int(raw_input())
x = []
for i in range(n):
    s = raw_input()
    x.append((int(s[0])*10+int(s[1]))*60+(int(s[3])*10+int(s[4])))
if n == 1:
    print "23:59"
else:
    x = sorted(x)
    ma = x[0]+24*60-x[n-1]
    for i in range(1,n):
        if ma < x[i]-x[i-1]:
            ma = x[i]-x[i-1]
    ma = ma-1
    hh = ma // 60
    mm = ma - hh * 60
    print '%02d:%02d'% (hh,mm)