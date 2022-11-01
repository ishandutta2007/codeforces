#include<bits/stdc++.h>
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
typedef long long int64;
const int maxn=1000005;
inline void read(int64 &x){
	x=0;char ch=getchar();int64 f=1;
	while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
int64 a[maxn];
int main(){
	int64 x,b;read(x);read(b);int counter=0,ans=0;
	rep(k,2,61){
		int64 tmp=1ll<<k;tmp--;
		rep(i,1,k-1){
			int64 v=tmp-(1ll<<(i-1));a[++counter]=v;
		}
	}
	rep(i,1,counter)if(a[i]>=x&&a[i]<=b)ans++;
	cout<<ans;
	return 0;
}