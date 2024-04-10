t = int(input())
for _ in range(t):
    s = input()
    c0 = 0
    c1 = 0
    for c in s:
        if c == '0':
            c0 += 1
        else:
            c1 += 1

    if c0 == c1:
        print(c0 - 1)
    else:
        print(min(c1, c0))