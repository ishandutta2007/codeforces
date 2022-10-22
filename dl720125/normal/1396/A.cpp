#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

inline int exgcd(int a,int b,int &x,int &y)
{
    if(b==0ll)
    {
        x=1ll,y=0ll;
        return a;
    }
    int ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

inline int getInv(int a,int mod)
{
    int x,y;
    int d=exgcd(a,mod,x,y);
    return d==1ll?(x%mod+mod)%mod:-1;
}

int n,a[100010]; 

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<"1 1\n"<<-a[1]<<"\n";
		cout<<"1 1\n0\n";
		cout<<"1 1\n0\n";
		return 0;
	}
	cout<<"1 1\n"<<-a[1]<<"\n";
	a[1]=0ll;
	cout<<"2 "<<n<<"\n";
	int inv=getInv(n-1,n);
	for(int i=2;i<=n;i++){
		if(a[i]%n==0ll){
			cout<<0ll<<" ";
		}
		else{
			int val=(n-a[i])%n;
			if(val<0) val+=n;
			int x=(val*inv)%n;
			cout<<x*(n-1)<<" ";
			a[i]+=x*(n-1);
		}
	}
	cout<<"\n";
	cout<<"1 "<<n<<"\n";
	for(int i=1;i<=n;i++){
		cout<<-a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}