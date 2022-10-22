#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=(1<<17);
const int X=2329142;
int n,m;
int a[N];
int tl[N],pre[N],cnt[N],P;
ll w[N];
int stk[N],top;
inline void ins(ll x){
	int c=((x^X)&(N-1));stk[++top]=c;
	int p;
	for(p=tl[c];p!=-1;p=pre[p]){
		if(w[p]==x){
			cnt[p]++;
			return;
		}
	}
	p=++P;
	pre[p]=tl[c];tl[c]=p;cnt[p]=1;w[p]=x;
}
int ans;
inline void checkid(int l,int r,int id){
	int i;
	for(i=l;i<=r;i++){
		if(i==id) continue;
		if((a[i]-a[id])%(i-id)) continue;
		ins((a[i]-a[id])/(i-id));
	}
	for(i=1;i<=P;i++) ans=max(ans,cnt[i]+1);
	for(i=0;i<=P;i++) pre[i]=w[i]=cnt[i]=0;
	P=0;
	while(top) tl[stk[top--]]=-1;
}
inline void checkd(int d){
	int i;
	for(i=1;i<=n;i++)
		ins(a[i]-1ll*i*d);
	for(i=1;i<=P;i++) ans=max(ans,cnt[i]);
	for(i=0;i<=P;i++) pre[i]=w[i]=cnt[i]=0;
	P=0;
	while(top) tl[stk[top--]]=-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	srand(chrono::system_clock::now().time_since_epoch().count());
	memset(tl,-1,sizeof(tl));
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	int B=320;
	for(i=-B;i<=B;i++)
		checkd(i);
	for(i=1;i<=n;i+=B){
		int r=min(i+B+B,n);
		for(j=i;j<=r;j++)
			checkid(i,r,j);
	}
	cout<<n-ans;
	return 0;
}