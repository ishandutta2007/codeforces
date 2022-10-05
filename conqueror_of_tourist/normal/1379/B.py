t = int(input())
for _ in range(t):
    l, r, m = map(int, input().split())
    for a in range(l, r + 1):
        rem = m % a
        if rem <= r - l and rem != m:
            print(a, l + rem, l)
            break
        if rem >= a - (r - l):
            print(a, l, l + (a - rem))
            break