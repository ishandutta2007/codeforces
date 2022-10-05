n, m = map(int, input().split())

out = []
currCount = 0
currVal = 0
while currVal < n:
    nex = currVal // 2
    if nex + currCount <= m:
        currCount += nex
        currVal += 1
        out.append(currVal)
    else:
        break


need = m - currCount
if need > 0:
    nex = currVal // 2
    val = currVal + 1
    val += 2 * (nex - need)
    if nex > need:
        out.append(val)
        currCount += need

l = len(out)
if l > n or m != currCount:
    assert(m > ((n-1) * (n-1))//4)
    print(-1)
else:
    assert(m <= ((n-1) * (n-1))//4)
    lorg = max(out)
    diff = lorg + 1

    start = (lorg+diff)//diff
    start += 2
    start *= diff
    start += 1
    while l < n:
        l += 1
        out.append(start)
        start += diff

    assert(len(out) == n)

    for i in range(n - 1):
        assert(out[i] < out[i + 1])
        assert(1 <= out[i])
        assert(out[i + 1] <= 10 ** 9)

    thing = set(out)
    
    count = 0
    for i in range(n):
        for j in range(i + 1, n):
            if out[i] + out[j] in thing:
                count += 1
                    
    assert(count == m)
        
    print(' '.join(map(str,out)))