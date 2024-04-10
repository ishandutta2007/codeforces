n, h, k = map(int, raw_input().split())
ans, now = 0, 0
for x in map(int, raw_input().split()):
	if now + x > h:
		ans += 1
		now = 0
	now += x
	ans += now / k
	now %= k
print ans + int(now > 0)