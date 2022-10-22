#include<iostream>
#include<algorithm>

using namespace std;
#define MOD 1000000000
long long f[10500], n, m, num[10500], q, x, v, l, r, d;
int main(){
    cin >> n >> m;
    f[0] = f[1] = 1;
    for(long long i = 1;i <= n;i++){
	cin >> num[i];
	f[i+1] = (f[i] + f[i - 1]) %MOD;
    }
    for(long long i = 0;i < m;i++){
	cin >> q;
	if(q == 1){
	    cin >> x >> v;
	    num[x] = v;
	}
	if(q == 2){
	    cin >> l >> r;
	    long long res = 0;
	    for(long long i = l;i <= r;i++){
		res += num[i] * f[i - l];
		res %= MOD;
	    }
	    cout << res << endl;
	}
	if(q == 3){
	    cin >> l >> r >> d;
	    for(long long i = l;i <= r;i++)num[i] += d;
	}
    }
    return 0;
}