#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+100;
bool used[maxn];
int a[maxn];
vector<int> prime;
int cnt[maxn];
bool exist[maxn];
void init(){
	for (int i=2;i<maxn;i++){
		if (!used[i]){
			prime.push_back(i);
		}
		for (int j=0;j<prime.size();j++){
			long long nxt =1ll * i * prime[j];
			if (nxt >= maxn)break;
			used[nxt] = 1;
			if (i % prime[j] == 0){
				break;
			}
		}
	}
//	cout<<"prime.size"<<prime.size()<<endl;
}
int n,q;
ll work(int x){
	vector<int> my_prime(0);
	int X = x;
	for (int i = 0;i<prime.size();i++){
		int pi = prime[i];
		if(1ll * pi * pi > X)break;
		if (x % pi == 0){
			my_prime.push_back(pi);
			while (x% pi == 0)x /= pi;
		}
	}
	//cout<<"now "<<x<<endl;
	if (x != 1){
		my_prime.push_back(x);
	}
	//cout<<"prime:";
	//for (int i=0;i<my_prime.size();i++){
	//	cout<<my_prime[i]<<" ";
	//}
	//cout<<endl;
	int sz = my_prime.size();
	ll ans = 0;
	for (int mask = 0;mask < (1<<sz);mask++){
		int cnt1 = __builtin_popcount(mask);
		int sig = 1;
		if(cnt1 &1){
			sig = -1;
		}
		int S = 1;
		for (int i=0;i<sz;i++){
			if (mask & (1<< i)){
				S *= my_prime[i];
			}
		}
		ans += 1ll * sig * cnt[S];
	}
	return ans;
}
inline void add(int ai,int val){
	for (int j=1;1ll* j*j <=ai;j++){
		if(ai %j == 0){
			cnt[j] += val;
			if(ai/j != j){
				cnt[ai/j] += val;
			}
		}
	}
}
ll ans;
int main(){
	init();
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	ans = 0;
	//cout<<"ans = "<<ans<<endl;
	while (q--){
		int idx;
		scanf("%d",&idx);
		int x = a[idx-1];
		if(exist[idx]){
			add(x,-1);
			ans -= work(x);
			exist[idx] = 0;
		}else{
			ans += work(x);
			add(x,1);
			exist[idx] = 1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}