import sys,io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

all_out = []

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    tot = sum(l)
    if tot % n:
        all_out.append('-1')
        continue
    want = tot // n

    out = []
    def put(i, j, x):
        if x:
            out.append(str(i+1)+' '+str(j+1)+' '+str(x))
            l[i] -= x * (i + 1)
            l[j] += x * (i + 1)
    
    for i in range(1, n):
        put(0, i, (-l[i]) % (i + 1))
        put(i, 0, l[i] // (i + 1))

    #print(l)
    for i in range(1, n):
        put(0, i, want)
    #print(l)

    all_out.append(str(len(out)))
    all_out += out
    
print('\n'.join(all_out))