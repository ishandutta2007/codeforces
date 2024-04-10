t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    l = list(map(int, input().split()))

    s = []
    out = [10**6] * n
    for i in range(n):
        if l[i]:
            out[i] = a[i]
        else:
            s.append(a[i])
    s.sort()
    for i in range(n):
        if out[i] == 10**6:
            out[i] = s.pop()
    print(' '.join(map(str,out)))