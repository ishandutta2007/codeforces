#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;cin>>a>>b>>c>>d;
		int val=c/d+(c%d!=0);
		if(a-b*c>0) cout<<-1<<'\n';
		else{
			int num=a;
			double x=a*1.0/(d*b)+0.5;
			int pos1=(int)x,pos2=(int)(x+1.0);
			if(pos1>=1&&pos1<=val) num=max(num,pos1*a-(pos1-1)*pos1*d*b/2);
			if(pos2>=1&&pos2<=val) num=max(num,pos2*a-(pos2-1)*pos2*d*b/2);
			num=max(num,val*a-(val-1)*val*d*b/2);
			cout<<num<<'\n';
		}
	}
	return 0;
}