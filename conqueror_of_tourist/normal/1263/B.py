t = int(input())

out = []

for _ in range(t):
    n = int(input())
    l = []
    count = 0
    bad = [False] * n
    
    for __ in range(n):
        pin = input()
        if pin in l:
            count += 1
            bad[__] = True
        l.append(pin)

    out.append(str(count))
    for i in range(n):
        if bad[i]:
            short = l[i][0:3]
            for c in '0123456789':
                if short + c not in l:
                    l[i] = (short + c)
                    break
        out.append(l[i])

print('\n'.join(out))