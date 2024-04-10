n = int(input())
import random

out = []
b2 = [n]
for i in range(41):
    out.append('{0} + {0}'.format(b2[-1]))
    b2.append(2*b2[-1])
b2 = b2[::-1]


basis = []
for j in range(1000):
    i = random.randint(1, n * n + 50)
    want = n * i
    for v in basis:
        if want ^ v < want:
            want = want ^ v
    if want > 0:
        add = []
        w2 = n * i
        for v in b2:
            if v <= w2:
                w2 -= v
                add.append(v)
        while len(add) > 1:
            u, v = add.pop(), add.pop()
            out.append('{1} + {0}'.format(u,v))
            add.append(u+v)

        assert(add[0] == n * i)

        w2 = n * i
        for v in basis:
            if w2 ^ v < w2:
                out.append('{1} ^ {0}'.format(w2,v))
                w2 = w2 ^ v
        
        basis.append(want)
        basis.sort(reverse = True)

print(len(out))
print('\n'.join(out))