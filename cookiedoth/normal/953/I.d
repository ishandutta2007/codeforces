module main;

import std.c.stdio;

static int [1440] all;
int [2000] t;

int format(char[] s) {
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

void pr(int x) {
    printf("%d", (x / 60) / 10);
    printf("%d", (x / 60) % 10);
    printf(":");
    printf("%d", (x % 60) / 10);
    printf("%d", (x % 60) % 10);
}

int main(string[] argv)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char [6] s;
        scanf("%s", &s);
        all[format(s)]++;
    }
    int j = 0;
	for (int i = 0; i < 1440; i++) {
	    if (all[i] > 0) t[j++] = i;
	}
	int ans = 0;
	for (int i = 1; i < j; i++) {
	    if (ans < t[i] - t[i - 1] - 1) {
	        ans = t[i] - t[i - 1] - 1;
	    }
	}
	if (ans < t[0] + 1439 - t[j - 1]) {
	    ans = t[0] + 1439 - t[j - 1];
	}
	pr(ans);
	return 0;
}