n, k, M, D = map(int, raw_input().split());
ans = 0;
for i in range(1, D+1):
	req = (i-1)*k + 1;
	x = n/req;
	x = min(x, M);
	if x == 0:
		continue;
	if (n/x > i*k + 1):
		continue;
	ans = max(ans, x * i);
print ans;