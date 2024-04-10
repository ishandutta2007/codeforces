import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    z = []
    o = []

    for i in range(n):
        if l[i]:
            o.append(i)
        else:
            z.append(i)

    o.reverse()

    out = 0
    while o and z and o[-1] < z[-1]:
        out += 1
        o.pop()
        z.pop()

    print(out)