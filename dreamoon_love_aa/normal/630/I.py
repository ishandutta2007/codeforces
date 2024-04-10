n = int(raw_input())
res = 8
res2 = (n-3)*4
for i in range(n-3):
    res = res * 4
res = res*3
if res2 > 0:
    for i in range(n-4):
        res2 = res2 * 4
res2 = res2*9
print res+res2