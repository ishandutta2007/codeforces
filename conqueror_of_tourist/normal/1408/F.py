n = int(input())
out = []
def p(a,b,d):
    out.append(str(a + 1 + d) + ' ' + str(b+1+d))

p2 = 1
while 2 * p2 <= n:
    p2 *= 2

for d in (0, n - p2):
    bit = 1
    while bit < p2:
        for i in range(p2):
            if i ^ bit > i:
                p(i, i ^ bit, d)
        bit *= 2
print(len(out))
print('\n'.join(out))