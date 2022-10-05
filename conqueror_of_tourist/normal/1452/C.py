t = int(input())
for _ in range(t):
    c1 = 0
    c2 = 0
    o = 0
    for c in input().strip():
        if c == '(':
            c1 += 1
        if c == ')':
            if c1:
                c1 -= 1
                o += 1
        if  c == '[':
            c2 += 1
        if c == ']':
            if c2:
                c2 -= 1
                o += 1
    print(o)