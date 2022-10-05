n = int(input())
l = list(map(int, input().split()))
tot = sum(l)
if tot % 3:
    print(0)
elif tot:
    b1 = tot // 3
    b2 = 2 * b1
    out = 0
    first = 0
    s = 0
    for v in l:
        s += v
        if s == b1:
            first += 1
        elif s == b2:
            out += first
    print(out)
else:
    s = 0
    count = -1
    for v in l:
        s += v
        if s == 0:
            count += 1
    print((count * (count - 1))//2)