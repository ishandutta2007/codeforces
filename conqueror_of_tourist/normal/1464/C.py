n, T = map(int, input().split())
s = input().strip()
l = [ord(c) - 97 for c in s]
T -= 2 ** l.pop()
T += 2 ** l.pop()

assert len(l) == n - 2

for v in l:
    T += 1 << v

if T % 2:
    print('No')
else:
    T //= 2
    l.sort(reverse = True)
    for v in l:
        p2 = 1 << v
        if p2 <= T:
            T -= p2

    if T == 0:
        print('Yes')
    else:
        print('No')