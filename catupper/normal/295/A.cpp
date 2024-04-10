#include<iostream>
#include<algorithm>

using namespace std;
long long op[105000][3], cnt[105000], ans[105000], f[105000];;
    long long n, m, k, a, b;
int main(){
    cin >> n >> m >> k;
    for(long long i = 0;i < n;i++){
	cin >> f[i + 1];
    }
    for(long long i = 0;i < m;i++){
	cin >> op[i + 1][0] >> op[i + 1][1] >> op[i + 1][2];
    }
    for(long long i = 0;i < k;i++){
	cin >> a >> b;
	cnt[a]++;
	cnt[b + 1]--;
    }
    for(long long i = 1;i < 105000;i++){
	cnt[i] += cnt[i - 1];
    }
    for(long long i = 0;i < m;i++){
	ans[op[i + 1][0]] += op[i + 1][2] * cnt[i + 1];
	ans[op[i + 1][1] + 1] -= op[i + 1][2] * cnt[i + 1];
    }
    for(long long i = 1;i < 105000;i++){
	ans[i] += ans[i - 1];
    }
    for(long long i = 1;i <= n;i++){
	cout << ans[i] + f[i];
	if(i != n)cout << ' ';
    }
    cout << endl;
    return 0;
}