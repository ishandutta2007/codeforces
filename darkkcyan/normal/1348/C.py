for testcase in range(int(input())):
    n, k = map(int, input().split())
    s = ''.join(sorted(input().strip()))

    if k == 1:
        print(s)
        continue

    if s[0] != s[k - 1]:
        print(s[k - 1])
        continue

    d = [0] * 26
    for i in s[k:]:
        d[ord(i) - ord('a')] += 1

    n -= k
    ans = s[k - 1]
    for i in range(26):
        if d[i] == 0:
            continue
        c = chr(i + ord('a'))
        if d[i] == n:
            ans += c * ((d[i] + k - 1) // k)
            break

        ans += c * d[i]
        for f in range(i + 1, 26):
            ans += chr(f + ord('a')) * d[f]
        break

    print(ans)