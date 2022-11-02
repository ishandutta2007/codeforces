#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
#define maxn 100009
using namespace std;
const long long INF = 1e17;
long long a[maxn],sum[maxn];
int n;
long long k;
map<long long,long long>mp;
int main(){
	cin >> n >> k;
	long long ans = 0;
	mp[0] = 1;
	for(int i = 1; i<=n;i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		a[i] = sum[i];
		if(k == 1){
			ans += mp[-1+a[i]];
		}
		else if(k == -1){
			ans += mp[-1+a[i]];
			ans += mp[1 + a[i]];
		}
		else{
			long long cur = 1;
			while(cur <= INF){
				ans += mp[-cur + a[i]];
				cur *= k;
			}
		}
		mp[sum[i]]++;
		//cout << ans << " " << sum[i] << " " << a[i] << endl;
	}
	cout << ans << endl;
	return 0;
}