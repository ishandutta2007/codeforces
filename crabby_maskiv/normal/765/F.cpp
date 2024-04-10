#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
const int M=320;
int n,m,B;
int a[N];
int lft[M],rgt[M],sz[M],pos[N];
pii b1[M][M],b0[N];
int pre[N],suf[N];
int l[N<<2],r[N<<2],ans[N<<2];
vector<int> q[M];
int val[N],tp[N],ts[N];
inline bool cmp(int x,int y){
	return r[x]>r[y];
}
inline void del(int x){
	if(pre[x]) suf[pre[x]]=suf[x];
	if(suf[x]) pre[suf[x]]=pre[x];
	pre[x]=suf[x]=0;
}
inline void add(int x){
	if(tp[x]) suf[tp[x]]=x;
	if(ts[x]) pre[ts[x]]=x;
	pre[x]=tp[x];
	suf[x]=ts[x];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	B=sqrt(n);
	for(i=1;i*B-B+1<=n;i++){
		lft[i]=i*B-B+1;
		rgt[i]=min(i*B,n);
		sz[i]=rgt[i]-lft[i]+1;
		for(j=lft[i];j<=rgt[i];j++){
			pos[j]=i;
			b1[i][j-lft[i]+1]={a[j],j};
		}
		sort(b1[i]+1,b1[i]+sz[i]+1);
	}
	for(i=1;i<=n;i++) b0[i]={a[i],i};
	sort(b0+1,b0+n+1);
	cin>>m;
	for(i=1;i<=m;i++) cin>>l[i]>>r[i];
	for(i=1;i<=m;i++){
		if(pos[l[i]]==pos[r[i]]){
			int la=-1e9,mn=1e9;k=pos[l[i]];
			for(j=1;j<=sz[k];j++){
				if(b1[k][j].sc>=l[i]&&b1[k][j].sc<=r[i]){
					mn=min(mn,b1[k][j].fr-la);
					la=b1[k][j].fr;
				}
			}
			ans[i]=mn;
		}
		else q[pos[l[i]]].push_back(i);
	}
	for(k=1;k<=pos[n];k++){
		for(i=1;i<n;i++){
			suf[b0[i].sc]=b0[i+1].sc;
			pre[b0[i+1].sc]=b0[i].sc;
		}
		pre[b0[1].sc]=suf[b0[n].sc]=0;
		for(i=1;i<=rgt[k];i++) del(i);
		for(i=n;i>rgt[k];i--){
			val[i]=1e9;
			if(suf[i]) val[i]=min(val[i],a[suf[i]]-a[i]); 
			if(pre[i]) val[i]=min(val[i],a[i]-a[pre[i]]); 
			del(i);
		}
		for(i=rgt[k]+2;i<=n;i++) val[i]=min(val[i],val[i-1]);
		sort(q[k].begin(),q[k].end(),cmp);
		for(i=1;i<n;i++){
			suf[b0[i].sc]=b0[i+1].sc;
			pre[b0[i+1].sc]=b0[i].sc;
		}
		pre[b0[1].sc]=suf[b0[n].sc]=0;
		for(i=1;i<lft[k];i++) del(i);
		int R=n;
		for(auto x:q[k]){
			while(R>r[x]) del(R--);
			ans[x]=val[r[x]];
			for(i=lft[k];i<=rgt[k];i++){
				tp[i]=pre[i];ts[i]=suf[i];
				del(i);
			}
			for(i=rgt[k];i>=l[x];i--){
				if(ts[i]) ans[x]=min(ans[x],a[ts[i]]-a[i]);
				if(tp[i]) ans[x]=min(ans[x],a[i]-a[tp[i]]);
				add(i);
			}
			for(i=l[x]-1;i>=lft[k];i--) add(i);
		}
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<'\n';
	return 0;
}