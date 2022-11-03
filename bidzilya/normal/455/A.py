def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())
a = get_ints()

kMaxA = int(1e5)

c = [0] * (kMaxA + 1)
for i in a:
    c[i] += 1

dp0, dp1 = 0, 0

for i in xrange(1, kMaxA + 1):
    dp0, dp1 = max(dp0, dp1), c[i] * i + dp0

print max(dp0, dp1)