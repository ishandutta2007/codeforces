#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long ll;
typedef long double ld;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const ll INF=9e18;

int n;
struct Node{
	ll x,y,z;
}node[100010];
bool check0(ll L0,ll R0,ll L1,ll R1,ll L2,ll R2,ll L3,ll R3,bool flg){
	if (L0%2) L0++; if (R0%2) R0--; if (L0>R0) return 0;
	if (L1%2) L1++; if (R1%2) R1--; if (L1>R1) return 0;
	if (L2%2) L2++; if (R2%2) R2--; if (L2>R2) return 0;
	if (L3%2) L3++; if (R3%2) R3--; if (L3>R3) return 0;
	ll A=L0,B=L1,C=L2;
	if ((ld)A+B+C>R3) return 0;
	ll d=A+B+C>=L3?0:L3-A-B-C;
	ll t=min(R0-L0,d); d-=t; A+=t;
	t=min(R1-L1,d); d-=t; B+=t;
	t=min(R2-L2,d); d-=t; C+=t;
	if (d) return 0;
	if (flg) printf("%I64d %I64d %I64d\n",(B+C)/2,(A+C)/2,(A+B)/2);
	return 1;
}
bool check1(ll L0,ll R0,ll L1,ll R1,ll L2,ll R2,ll L3,ll R3,bool flg){
	if (L0%2==0) L0++; if (R0%2==0) R0--; if (L0>R0) return 0;
	if (L1%2==0) L1++; if (R1%2==0) R1--; if (L1>R1) return 0;
	if (L2%2==0) L2++; if (R2%2==0) R2--; if (L2>R2) return 0;
	if (L3%2==0) L3++; if (R3%2==0) R3--; if (L3>R3) return 0;
	ll A=L0,B=L1,C=L2;
	if ((ld)A+B+C>R3) return 0;
	ll d=A+B+C>=L3?0:L3-A-B-C;
	ll t=min(R0-L0,d); d-=t; A+=t;
	t=min(R1-L1,d); d-=t; B+=t;
	t=min(R2-L2,d); d-=t; C+=t;
	if (d) return 0;
	if (flg) printf("%I64d %I64d %I64d\n",(B+C)/2,(A+C)/2,(A+B)/2);
	return 1;
}
bool check(ll k,bool flg=0){
	ll L0=-INF,L1=-INF,L2=-INF,L3=-INF;
	ll R0=INF,R1=INF,R2=INF,R3=INF;
	for (int i=1;i<=n;i++){
		R0=min(R0,k-node[i].x+node[i].y+node[i].z);
		L0=max(L0,-k-node[i].x+node[i].y+node[i].z);
		R1=min(R1,k+node[i].x-node[i].y+node[i].z);
		L1=max(L1,-k+node[i].x-node[i].y+node[i].z);
		R2=min(R2,k+node[i].x+node[i].y-node[i].z);
		L2=max(L2,-k+node[i].x+node[i].y-node[i].z);
		R3=min(R3,k+node[i].x+node[i].y+node[i].z);
		L3=max(L3,-k+node[i].x+node[i].y+node[i].z);
	}
	return check0(L0,R0,L1,R1,L2,R2,L3,R3,flg)||check1(L0,R0,L1,R1,L2,R2,L3,R3,flg);
}
void init(){}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) node[i]=(Node){read(),read(),read()};
	ll l=0,r=3e18,mid,ans;
	while (l<=r){
		mid=l+r>>1;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	check(ans,1);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}