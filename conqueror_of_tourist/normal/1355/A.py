t = int(input())
for _ in range(t):
    a, K = map(int, input().split())
    curr = 1
    while curr < K:
        curr += 1
        s = str(a)
        big = max(s)
        smol = min(s)
        diff = (ord(big) - 48) * (ord(smol) - 48)
        if diff == 0:
            break
        a += diff
    print(a)