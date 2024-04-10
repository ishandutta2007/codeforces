#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=1e9+7;
int n,ord[200004],suf[200004],N,ans;
pii info[200004];
int f[200004],g[200004],bit[200004],a[200004];
bool cmp(int A,int B){return info[A]<info[B];}
void upd(int i,int x){for(;i<=n;i+=i&-i)(bit[i]+=x)%=M;}
int qry(int i){int ret=0;for(;i;i-=i&-i)(ret+=bit[i])%=M;return ret;}
void solve(){
	scanf("%d",&n),ans=0;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),info[i]={x,-i},ord[i]=i;
	sort(ord+1,ord+n+1,cmp),N=0;
	for(int i=1;i<=n;i++)a[ord[i]]=++N;
	suf[n+1]=0;
	for(int i=n;i;i--)suf[i]=max(suf[i+1],a[i]);
	for(int i=1;i<=n;i++)bit[i]=0;
	for(int i=1;i<=n;i++)f[i]=qry(a[i])+1,upd(a[i],f[i]);
	for(int i=1;i<=n;i++)bit[i]=0;
	for(int i=n;i;i--)g[i]=qry(n-a[i]+1)+1,upd(n-a[i]+1,g[i]),(ans+=(ll)f[i]*g[i]%M)%=M;
	for(int i=1;i<=n;i++)bit[i]=0;
	int cur=1;
	for(int i=n;i;i--)if(suf[i]!=suf[i+1]){
		(ans+=M-f[i])%=M;
		vector<int>v;
		while(cur<=n&&a[ord[cur]]<suf[i])v.push_back(ord[cur++]);
		sort(v.begin(),v.end(),greater<int>());
		vector<pair<int,int> >del;
		upd(n-a[i]+1,1),del.push_back({n-a[i]+1,1});
		for(int j=0;j<v.size();j++)if(a[v[j]]>suf[i+1]&&v[j]<i){
			int tmp=qry(n-a[v[j]]+1);
			(ans+=M-(ll)f[v[j]]*tmp%M)%=M;
			upd(n-a[v[j]]+1,tmp),del.push_back({n-a[v[j]]+1,tmp});
		}
		for(auto x:del)upd(x.fi,M-x.se);
	}
	printf("%d\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)solve();
}