import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    s = input().strip()

    o = []
    l = '~'
    for c in s:
        if c > l or (c == l and s[0] == s[1]):
            break
        o.append(c)
        l = c

    oo = ''.join(o)

    out.append(oo+oo[::-1])
print('\n'.join(map(str,out)))