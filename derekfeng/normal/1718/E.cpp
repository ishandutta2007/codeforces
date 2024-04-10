#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=2e5+4;
int n,m;bool rev;
vector<vector<int> >a,b;
vector<pii>ga[N],gb[N];
int va[N],vb[N];
int pl[N],pr[N];
int ta[N],tb[N];
struct info{
	int nl,nr,nm;
	vector<pair<pii,int> >edg;
	info(){nl=nr=nm=0,edg.clear();};
	bool operator==(const info &o){
		return nl==o.nl&&nr==o.nr&&nm==o.nm&&edg==o.edg;
	}
};
info cur;int cnt;
vector<pair<int,info> >vec;
bool del[N],ok[N];
void dfsa(int x){
	va[x]=++cnt;if(x<=n)cur.nl++;else cur.nr++;
	for(auto [c,y]:ga[x]){
		cur.nm++;if(!va[y])dfsa(y);
		if(va[x]<va[y])cur.edg.push_back({{va[x],va[y]},c});
	}
}
void dfsb(int x){
	vb[x]=++cnt;if(x<=n)cur.nl++;else cur.nr++;
	for(auto [c,y]:gb[x]){
		cur.nm++;if(!vb[y])dfsb(y);
		if(vb[x]<vb[y])cur.edg.push_back({{vb[x],vb[y]},c});
	}
}
vector<pii>proc(int *P,int n){
	vector<pii>ans;
	for(int i=1;i<=n;i++){
		while(P[i]!=i){
			ans.push_back({i,P[i]});
			swap(P[i],P[P[i]]);
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);if(n>m)swap(n,m),rev=1;
	a.resize(n+1),b.resize(n+1);
	for(int i=0;i<=n;i++)a[i].resize(m+1);
	for(int i=0;i<=n;i++)b[i].resize(m+1);
	if(rev){
		for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)scanf("%d",&a[i][j]);
		for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)scanf("%d",&b[i][j]);
	}else{
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&b[i][j]);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(a[i][j])ga[i].push_back({a[i][j],j+n}),ga[j+n].push_back({a[i][j],i});
		if(b[i][j])gb[i].push_back({b[i][j],j+n}),gb[j+n].push_back({b[i][j],i});
	}
	for(int i=1;i<=n+m;i++)sort(ga[i].begin(),ga[i].end()),sort(gb[i].begin(),gb[i].end());
	for(int i=1;i<=n;i++)if(!vb[i])cnt=0,cur=info(),dfsb(i),vec.push_back({i,cur});
	for(int i=1;i<=n;i++)if(!ok[i]){
		memset(va,0,sizeof(va));
		cnt=0,cur=info(),dfsa(i);
		for(int j=0;j<vec.size();j++)if(!del[j]&&vec[j].second==cur){
			memset(vb,0,sizeof(vb));
			cnt=0,dfsb(vec[j].first),del[j]=1;
			for(int k=1;k<=n+m;k++){
				if(va[k])ta[va[k]]=k,ok[k]=1;
				if(vb[k])tb[vb[k]]=k;
			}
			for(int k=1;k<=cnt;k++){
				if(ta[k]<=n)pl[ta[k]]=tb[k];
				else pr[ta[k]-n]=tb[k]-n;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)if(!pl[i])return puts("-1"),0;
	vector<int>d;
	for(int i=1;i<=m;i++)if(gb[n+i].empty())d.push_back(i);
	for(int i=1;i<=m;i++)if(!pr[i])pr[i]=d.back(),d.pop_back();
	vector<pii>p0=proc(pl,n),p1=proc(pr,m);
	printf("%d\n",(int)p0.size()+(int)p1.size());
	if(rev){
		for(auto [a,b]:p0)printf("2 %d %d\n",a,b);
		for(auto [a,b]:p1)printf("1 %d %d\n",a,b);
	}else{
		for(auto [a,b]:p0)printf("1 %d %d\n",a,b);
		for(auto [a,b]:p1)printf("2 %d %d\n",a,b);
	}
}