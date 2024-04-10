import sys, random
input = sys.stdin.readline

UUU = random.randint(1, 174747471)

out = []
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    '''
    res = n
    curr = []
    for v in a:
        for u in curr:
            if u ^ v < v:
                v = u ^ v
        if v == 0:
            res -= 1
            curr = []
        else:
            curr.append(v)
            curr.sort(reverse=True)
    out.append(res)'''

    save = {}
    save[UUU] = 0
    last = 0
    curr = UUU
    for v in a:
        curr ^= v
        if curr in save:
            last = max(last, save[curr] + 1)
        save[curr] = last
    out.append(n - last)
print('\n'.join(map(str,out)))