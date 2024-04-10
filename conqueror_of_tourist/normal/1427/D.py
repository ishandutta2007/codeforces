n = int(input())
c = list(map(int, input().split()))
c2 = c[::]
out = []
for i in range(1, n):
    ind = c2.index(i)
    if i == ind + 1:
        continue

    sizes = [1] * (i - 1) + [ind - i + 2] + [1] * (n - ind - 1)

    if len(sizes) > 1:
        if c2 == c:
            sizesr = sizes
        else:
            sizesr = sizes[::-1]

        out.append(str(len(sizesr)) + ' ' + ' '.join(map(str,sizesr)))

        lists = []
        curr = 0
        for v in sizes:
            lists.append(c2[curr:curr+v])
            curr += v
        lists.reverse()
        c2 = []
        for l in lists:
            c2 += l

        lists = []
        curr = 0
        for v in sizesr:
            lists.append(c[curr:curr+v])
            curr += v
        lists.reverse()
        c = []
        for l in lists:
            c += l
        
    c2.reverse()

if c != c2:
    out.append(str(n) + ' 1'*n)
    c = c[::-1]

assert(c == list(range(1,n+1)))

print(len(out))
print('\n'.join(out))