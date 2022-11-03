def get_ints():
    return map(int, raw_input().strip().split(' '))

n, k = get_ints()
a = [0] * 26
s = raw_input()
for c in s:
    a[ord(c) - ord('A')] += 1
ans = 0
for x in sorted(a, reverse=True):
    d = min(k, x)
    ans += d * d
    k -= d
print ans