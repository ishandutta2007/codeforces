n = int(input())
l = list(map(int, input().split()))

bitcount = [0] * 64
for v in l:
    i = 0
    while v:
        if v & 1:
            bitcount[i] += 1
        v >>= 1
        i += 1
        

bitstart = 0
for i in range(64):
    if bitcount[i] == 1:
        bitstart = i

start = 0
for v in l:
    if 1 << bitstart & v:
        start = v
        break


print(' '.join(map(str, sorted(l, key = lambda x: abs(x - start)))))