n = input()
a = map(int, raw_input().split())
cnt = [0, 0, 0, 0, 0]
for x in a:
	cnt[x] += 1

ans = cnt[4]
ans += min(cnt[3], cnt[1]);
g = min(cnt[3], cnt[1]);
cnt[3] -= g;
cnt[1] -= g;
ans += cnt[3];
ans += cnt[2]/ 2;
cnt[2] %= 2;
if cnt[2]:
	ans += 1;
	cnt[1] = max(cnt[1] - 2, 0);
ans += cnt[1]/ 4;
cnt[1] %= 4;
if cnt[1]:
	ans += 1;
print ans