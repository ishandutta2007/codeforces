a = raw_input()

res = 1
head = 0
al = set()
if a[0] == "?": res = 9
elif a[0] not in "1234567890":
    al.add(a[0])
    head = 1

for x in xrange(1, len(a)):
    if(a[x] in "1234567890"):continue
    if(a[x] == "?"):res *= 10
    else:
       al.add(a[x])

def p(x):
    if(x == 0):return 1
    return p(x - 1) * x

res *= p(10) / p(10 - len(al))

if head:
    res = res * 9 / 10

print res