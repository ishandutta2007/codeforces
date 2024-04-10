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

int n,q,a[300010],flag[300010],x[300010],y[300010],k[300010];
int val[31][600010];
long long bit[31][300010];
vector<int> vec;

inline void add(long long b[],int p,int v)
{
	while(p<=n){
		b[p]+=1ll*v;
		p+=p&(-p);
	}
}

inline long long sum(long long b[],int p)
{
	long long s=0ll;
	while(p!=0){
		s+=b[p];
		p-=p&(-p);
	}
	return s;
}

signed main()
{
	unsigned seed=chrono::steady_clock::now().time_since_epoch().count();
	mt19937 Rand(seed);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],vec.push_back(a[i]);
	for(int i=1;i<=q;i++){
		cin>>flag[i];
		if(flag[i]==1) cin>>x[i]>>y[i],vec.push_back(y[i]);
		else cin>>x[i]>>y[i]>>k[i];
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=1;i<=(int)vec.size();i++){
		for(int j=1;j<=30;j++) val[j][i]=Rand()%1000000000+1;
	}
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin()+1;
		for(int j=1;j<=30;j++) add(bit[j],i,val[j][a[i]]);
	}
	for(int i=1;i<=q;i++){
		if(flag[i]==1){
			y[i]=lower_bound(vec.begin(),vec.end(),y[i])-vec.begin()+1; 
			for(int j=1;j<=30;j++){
				add(bit[j],x[i],val[j][y[i]]-val[j][a[x[i]]]);
			}
			a[x[i]]=y[i];
		}
		else{
			bool flag=true;
			for(int j=1;j<=30;j++){
				long long num=sum(bit[j],y[i])-sum(bit[j],x[i]-1);
				if(num%k[i]!=0){
					flag=false;break;
				}
			}
			if(flag) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}