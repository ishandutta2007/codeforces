import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    odd = []
    for i in range(n):
        if l[i] % 2 == 1:
            odd.append(i)
    poss = [10 ** 20]

    if len(odd) == n//2:
        want = range(1,n,2)
        assert len(want) == len(odd)
        val = 0
        for i in range(n//2):
            val += abs(odd[i] - want[i])
        poss.append(val)

    if len(odd) == (n + 1)//2:
        want = range(0,n,2)
        assert len(want) == len(odd)
        val = 0
        for i in range((n + 1)//2):
            val += abs(odd[i] - want[i])
        poss.append(val)

    o = min(poss)
    if o == 10 ** 20:
        o = -1
    out.append(o)
print('\n'.join(map(str,out)))