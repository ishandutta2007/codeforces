res = 0
for x in xrange(input()):
    a = raw_input().strip('X')
    if(a[0] == '+'):res += 1
    else :res -= 1

print res