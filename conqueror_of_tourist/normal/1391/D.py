import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = []
for _ in range(n):
    l.append(input().strip())

def witch(s):
    out = 0
    if s[0] != s[1]:
        out += 2
    if s[1] != s[2]:
        out += 1
    return out

if n >= 4 and m >= 4:
    print(-1)
else:
    if n < m:
        n, m = m, n
        l = [''.join([l[j][i] for j in range(m)]) for i in range(n)]
    if m == 1:
        print(0)
    elif m == 2:
        even = 0
        odd = 0
        first = l.pop(0)
        if first == '00' or first == '11':
            odd += 1
        else:
            even += 1
        for nex in l:
            if nex == '00' or nex == '11':
                odd, even = even + 1, odd
            else:
                odd, even = even, odd + 1
        print(min(even, odd))
    elif m == 3:
        #ee, eo, oe, oo = [0, 0, 0 ,0]
        ll = [0, 0, 0, 0]
        for nex in l:
            ll.reverse()
            ll[witch(nex)] += 1
        print(n - max(ll))