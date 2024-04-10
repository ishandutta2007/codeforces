n = int(input())
c = list(map(int, input().split()))
t = list(map(int, input().split()))

def comp(l):
    out = 0
    for v in l:
        out += v * v
    for i in range(n-1):
        out -= l[i] * l[i + 1]
    return out

#Necessary but clearly not sufficient
if c[0] == t[0] and t[-1] == c[-1] and comp(c) == comp(t):
    print('Yes')
else:
    print('No')