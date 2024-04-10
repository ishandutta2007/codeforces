t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    l = list(map(int, input().split()))
    l.sort(reverse=True)
    out = 0
    count = 0
    for v in l:
        if v * (count + 1) >= x:
            out += 1
            count = 0
        else:
            count += 1
    print(out)