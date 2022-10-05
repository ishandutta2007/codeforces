n = int(input())


starts = []
ends = []
fulls = 0
#Testing Validity
for _ in range(n):
    s = input()
    count = 0
    mn = 0
    for c in s:
        if c == '(':
            count += 1
        else:
            count -= 1
            mn = min(mn, count)
    #print(count, mn)

    if count > 0:
        if mn == 0:
            starts.append(count)
    elif count < 0:
        if mn == count:
            ends.append(-1 * count)
    else:
        if mn == 0:
            fulls += 1

starts.sort()
ends.sort()

out = 0
while len(starts) > 0 and len(ends) > 0:
    st = starts[0]
    en = ends[0]

    if st < en:
        starts.pop(0)
    elif st > en:
        ends.pop(0)
    else:
        out += 1
        starts.pop(0)
        ends.pop(0)

print(out + fulls//2)