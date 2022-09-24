for _ in range(int(input())):
    n, k = map(int, input().split())
    s, l = input(), [""]*k
    for i in range(k):
        l[i]=s[i::k]
    ans, c1, c2 = True, 0, 0
    for i in range(k):
        c1 += (1 if "1" in l[i] else -1)
        c2 += (-1 if "0" in l[i] else 1)
        ans &= not ("0" in l[i] and "1" in l[i])
    ans &= (c1 <= 0 and 0 <= c2)
    print("YES" if ans else "NO")