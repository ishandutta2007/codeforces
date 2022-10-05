v, u = map(int, input().split())

count = [0] * 100
index = 0

works = True
while u >= 0 and v >=0 and (v > 0 or u > 0):
    u2 = u & 1
    v2 = v & 1
    if u2 != v2:
        u -= 1
        if index:
            count[index - 1] += 2
        else:
            works = False
            break
    elif u2:
        u -= 1
        v -= 1
        count[index] += 1
    else:
        u >>= 1
        v >>= 1
        index += 1

if works and u >= 0 and v >= 0:
    out = []
    for i in range(100):
        while len(out) < count[i]:
            out.append(0)
        for j in range(count[i]):
            out[j] ^= 1 << i
    print(len(out))
    print(' '.join(map(str,out)))
else:
    print(-1)