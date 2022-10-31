k = input()
s = sorted(list(raw_input()))

c = sum(int(x) for x in s)
ans = 0
for x in s:
    if c >= k:
        break
    c += min(k - c, 9 - int(x))
    ans += 1
print ans