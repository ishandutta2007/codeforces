s = input().strip()
x, y = map(int,input().split())
if x < y:
    x, y = y, x
    ss = []
    for c in s:
        if c == '0':
            ss.append('1')
        elif c == '1':
            ss.append('0')
        else:
            ss.append('?')
    s = ''.join(ss)

#x >= y

const = 0
out = []

zc = oc = 0
zb = []
ob = []

for c in s:
    if c == '1':
        oc += 1
        const += x * zc
    elif c == '0':
        zc += 1
        const += y * oc
    else:
        zb.append(zc)
        ob.append(oc)

za = [zc - v for v in zb]
oa = [oc - v for v in ob]

#All zeroes
curr = sum(ob) * y + sum(oa) * x
out.append(curr)

k = len(zb)
for i in range(k):
    curr -= x * oa[i]
    curr -= y * (ob[i] + i)

    curr += x * zb[i]
    curr += y * (za[i] + (k - i - 1))
    out.append(curr)

print(const + min(out))