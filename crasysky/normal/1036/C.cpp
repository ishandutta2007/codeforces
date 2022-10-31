#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long read(){
    long long cnt = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9'){
        cnt = cnt * 10 + ch - '0';
        ch = getchar();
    }
    return cnt;
}

long long f[20][5][2], a[20];
long long getans(long long x){
	if (x == 0)
		return 0;
	int len = 0;
	long long tmp = x;
	for (unsigned long long i = 1; i <= x; i *= 10){
		a[++ len] = tmp % 10;
		tmp /= 10;
	}
	for (int i = 1; i <= len / 2; ++ i)
		swap(a[i], a[len - i + 1]);
	memset(f, 0, sizeof(f));
	f[0][0][1] = 1;
	for (int i = 1; i <= len; ++ i){
		f[i][0][0] = 1;
		for (int j = 1; j <= 3; ++ j){//0
			f[i][j][0] = f[i - 1][j - 1][0] * 9 + f[i - 1][j][0];
			if (a[i])
				f[i][j][0] += f[i - 1][j - 1][1] * (a[i] - 1) + f[i - 1][j][1];
			f[i][j][1] = f[i - 1][j - (a[i] > 0 ? 1 : 0)][1];
		}
	}
	int xx = f[len][1][0] + f[len][2][0] + f[len][3][0] + f[len][1][1] + f[len][2][1] + f[len][3][1];
	//cout << xx  << endl;
	return xx;
}

int main(){
	int q = read();
	while (q --){
		long long l = read(), r = read(), len = 0;
		cout << getans(r) - getans(l - 1) << endl;
	}
}
/*
1
99999999999999999
100000000000000000
*/
/*
#include <iostream>
#include <cstdio>
using namespace std;

long long read(){
    long long cnt = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9'){
        cnt = cnt * 10 + ch - '0';
        ch = getchar();
    }
    return cnt;
}
int main(){
	int q = read();
	while (q --){
		long long x = read(), y = read(), k = read();
		long long cnt = max(x, y);
		if (cnt > k)
			printf("-1\n");
		else{
			if (x != y)
				printf("%lld\n", min(x, y) + k - cnt);
			else{
				if (k == cnt + 1)
					printf("%lld\n", cnt - 1);
				else
			}
		}
	}
}
*/