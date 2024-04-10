#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int a[11];
char s[11];

signed main()
{
	ios::sync_with_stdio(false);
	int k;cin>>k;
	int cnt=1,num=1;
	for(int i=1;i<=10;i++) a[i]=1;
	while(num<k){
		num=num/a[cnt];
		a[cnt]++;
		num*=a[cnt];
		cnt++;
		if(cnt==11) cnt=1;
	}
	s[1]='c';s[2]='o';s[3]='d';s[4]='e';s[5]='f';s[6]='o';s[7]='r';s[8]='c';s[9]='e';s[10]='s';
	for(int i=1;i<=10;i++){
		for(int j=1;j<=a[i];j++){
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}