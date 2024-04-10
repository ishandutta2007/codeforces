def get_ints():
    return map(int, raw_input().strip().split(' '))

s = raw_input()
k = int(raw_input())
w = get_ints()

ans = 0
for i in xrange(len(s)):
    ans += w[ord(s[i]) - ord('a')] * (i + 1)

for i in xrange(k):
    ans += max(w) * (i + len(s) + 1)

print ans