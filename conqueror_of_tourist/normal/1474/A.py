T = int(input())
for _ in range(T):
    n = int(input())
    s = input()
    last = -1
    out = []
    for c in s:
        if int(c) + 1 == last:
            last = int(c)
            out.append('0')
        else:
            last = int(c)  +1
            out.append('1')
    print(''.join(out))