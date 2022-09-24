import std.algorithm, std.conv, std.range, std.stdio, std.string;

int main(string[] argv)
{
	int n, p1, m;
	scanf("%d %d %d", &n, &p1, &m);
	long p = p1;
	long [] d = new long[n + 1];
	long [] t = new long[n + 1];
	for(int i = 0; i < n; i++) {
		scanf("%lld %lld", &t[i], &d[i]);
	}
	d[n] = 1152921504606846976L;
	t[n] = m + 1;
	long curday = 1;
	long money = 0;
	long answer = 0;
	for(int i = 0; i <= n; i++) {
		long lastday = t[i];
		long needdays = 0;
		if (money >= 0) {
			needdays = money / p;			
		}
		if (lastday - curday > needdays) {
			answer += (lastday - curday) - needdays;
		}
		money -= p * (lastday - curday + 1);
		curday = lastday + 1;
		money += d[i];
		if (money < 0) {
			answer++;
		}
	}
	printf("%lld\n", answer);
	return 0;
}