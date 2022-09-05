#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
ll l,r;int res,cnt[20],a[20];
int lv[20],rv[20],mx;bool ok;
inline void ckl(int *a,int dep, int cur){
	if(ok)return;
	int mx=0;rep(i,1,9)if(a[i])mx=i;
	per(i,dep-1,0){
		if(lv[i+1]){
		    if(a[lv[i+1]]<=0)return;a[lv[i+1]]--;cur--;
		    if(!cur)break;while(!a[mx])mx--;
		}
		if(mx>=lv[i]+1&&cur>=1&&cur<=i+1){ok=1;return;}
	}
}
inline void ckr(int *a,int dep, int cur){
	if(ok)return;
	per(i,dep-1,0){
		if(rv[i+1]){if(a[rv[i+1]]<=0)return;a[rv[i+1]]--;cur--;}
		if(rv[i]>0&&cur<=i){ok=1;return;}
		rep(j,1,rv[i]-1)if(a[j]&&cur>=1&&cur<=i+1){ok=1;return;}
	}
}
void dfs(int dep, int cur){
	if(dep>9){
		rep(i,1,9)a[i]=cnt[i];ok=0;
	//	rep(i,1,9)cerr<<cnt[i];cerr<<endl;
		per(i,mx,0)if(lv[i]!=rv[i]){
			bool ok_tmp=1;
			per(j,mx,i+1)if(lv[j]>=1)a[lv[j]]--,ok_tmp&=a[lv[j]]>=0,cur--;
			rep(j,lv[i]+1,rv[i]-1)if(a[j]>=1&&ok_tmp&&cur>=1&&cur<=i+1){ok=1;break;}
		//	if(cnt[2])cerr<<i<<' '<<ok_tmp<<endl;
			//l
			static int b[20];
			rep(j,0,9)b[j]=a[j];if(ok_tmp)ckl(b,i,cur);
			//r
			rep(j,0,9)b[j]=a[j];if(ok_tmp)ckr(b,i,cur);
			break;
		}
	//	if(ok){rep(i,1,9)cerr<<cnt[i];cerr<<endl;}
		res+=ok;
		return;
	}
	rep(i,0,mx+1-cur)
		cnt[dep]=i,dfs(dep+1,cur+i);
}
int main() {
	read(l);read(r);l--;r++;
	for(ll i=0,x=1;x<=r;x*=10,i++)
		mx=i,lv[i]=l/x%10,rv[i]=r/x%10;
	/*cerr<<mx<<endl;
	per(i,mx,0)cerr<<lv[i];cerr<<endl;
	per(i,mx,0)cerr<<rv[i];cerr<<endl;*/
	dfs(1,0);cout<<res;
	return 0;
}