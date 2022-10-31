#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int B1=1003,P1=1e5+7,B2=23,P2=1e9+7,S=(1<<15)-1,B=15;
map<int,int> mp[P1]; int a[102],cnt[S+1];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,S) cnt[i]=cnt[i&i-1]+1;
	rep(s,0,S){
		int v1=0,v2=0;
		rep(i,1,n){
			int b=cnt[(a[i]&S)^s];
			v1=((ll)v1*B1+b)%P1;
			v2=((ll)v2*B2+b)%P2;
		}
		mp[v1][v2]=s;
	}
	rep(c,0,30)
		rep(s,0,S){
			int v1=0,v2=0;
			rep(i,1,n){
				int b=c-cnt[(a[i]>>B)^s];
				if (b<0){ v2=-1; break; }
				v1=((ll)v1*B1+b)%P1;
				v2=((ll)v2*B2+b)%P2;
			}
			if (mp[v1].count(v2)){
				printf("%d\n",s<<B|mp[v1][v2]);
				return 0;
			}
		}
	puts("-1"); return 0;
}