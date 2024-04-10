#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
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

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		multiset<long long> s;
		multiset<long long>::iterator it;
		long long sum=0ll;
		for(int i=1;i<=n;i++){
			long long x;cin>>x;sum+=x;
			s.insert(x);
		}
		if(n==1){
			if((*s.begin())==1) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		long long a=1ll,b=1ll,num=2ll;
		vector<long long> v;v.push_back(a);v.push_back(b);
		while(num<sum){
			long long x=a+b;num+=x;
			a=b;b=x;v.push_back(x);
		}
		if(num>sum){
			cout<<"NO\n";
			continue;
		}
		bool flag=true;
		while(!v.empty()){
			long long x=v.back();v.pop_back();
			it=s.end();it--;
			long long p=(*it),q=-1;
			if(it!=s.begin()){
				it--;q=(*it);
			}
			if(p<x){
				flag=false;break;
			}
			if(q<x){
				if(v.empty()){
					s.erase(s.find(p));continue;
				}
				long long y=v.back();
				if(p>=x+y){
					long long now=x;
					for(int i=v.size()-2;i>=0;i-=2) now+=v[i];
					if(now<p){
						flag=false;break;
					}
					s.erase(s.find(p));
					for(int i=v.size()-1;i>=0;i-=2){
						it=s.end();it--;
						long long cur=(*it);
						if(cur<v[i]){
							flag=false;break;
						}
						s.erase(s.find(cur));
						if(cur>v[i]) s.insert(cur-v[i]);
					}
					break;
				}
				else{
					s.erase(s.find(p));
					if(p>x) s.insert(p-x);
				}
			}
			else{
				long long now=0;
				for(int i=v.size()-1;i>=0;i-=2) now+=v[i];
				if(now<q){
					flag=false;break;
				}
				s.erase(s.find(q));s.erase(s.find(p));
				if(p>x) s.insert(p-x);
				for(int i=v.size()-2;i>=0;i-=2){
					it=s.end();it--;
					long long cur=(*it);
					if(cur<v[i]){
						flag=false;break;
					}
					s.erase(s.find(cur));
					if(cur>v[i]) s.insert(cur-v[i]);
				}
				break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}