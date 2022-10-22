#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair 
const int H=257,M=998244353;
void outno(){cout<<"No solution";exit(0);}
int n,m;
int cnt[4][4];
vector<pii>g[100004][4],f[100004][4]; 
int L[4],R[4];
bool vis[2][100004][4];
vector<pii>v1,v2;
void gotverg(int x,int y){
	vis[0][x][y]=1;
	v1.push_back(mkp(x,y));
	for(auto z:g[x][y])if(!vis[0][z.fi][z.se])gotverg(z.fi,z.se);
}
void gotverf(int x,int y){
	vis[1][x][y]=1;
	v2.push_back(mkp(x,y));
	for(auto z:f[x][y])if(!vis[1][z.fi][z.se])gotverf(z.fi,z.se);
}
vector<pii>minshow(vector<pii>v){
	vector<pii>res;
	int N=v.size(),ans=0;
	int i=0,j=1,k=0,tmp;
	while(i<N&&j<N&&k<N){
		if(v[(i+k)%N].se==v[(j+k)%N].se)k++;
		else{
			if(v[(i+k)%N].se>v[(j+k)%N].se)i+=k+1;
			else j+=k+1;
			if(i==j)j++;
			k=0;
		}
	}
	tmp=min(i,j);
	for(int i=0;i<N;i++)res.push_back(v[(tmp+i)%N]);
	return res;
}
int gethash(vector<pii>v){
	int ans=0;
	for(auto x:v)ans=((ll)ans*H+x.se+22)%M;
	return ans;
}
int ans1[100004],ans2[100004];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)g[i][0].push_back(mkp(i,2)),g[i][2].push_back(mkp(i,0));
	for(int i=1;i<=m;i++)g[i][3].push_back(mkp(i,1)),g[i][1].push_back(mkp(i,3));
	for(int i=1;i<=n;i++)f[i][0].push_back(mkp(i,2)),f[i][2].push_back(mkp(i,0));
	for(int i=1;i<=m;i++)f[i][3].push_back(mkp(i,1)),f[i][1].push_back(mkp(i,3));
	for(int i=1;i<=n+m;i++){
		char c1,c2;int a,b;
		int i1,i2;
		cin>>c1>>c2>>a>>b;
		if(c1=='L')i1=0;if(c1=='T')i1=1;if(c1=='R')i1=2;if(c1=='B')i1=3;
		if(c2=='L')i2=0;if(c2=='T')i2=1;if(c2=='R')i2=2;if(c2=='B')i2=3;
		if(i1>i2)swap(i1,i2),swap(a,b);
		cnt[i1][i2]++;
		g[a][i1].push_back(mkp(b,i2)),g[b][i2].push_back(mkp(a,i1));
	}
	if(cnt[0][2]&&cnt[1][3])outno();
	R[0]=R[2]=n+1,R[1]=R[3]=m+1; 
	for(int i=0;i<cnt[0][1];i++)++L[0],++L[1],f[L[0]][0].push_back(mkp(L[1],1)),f[L[1]][1].push_back(mkp(L[0],0)); 
	for(int i=0;i<cnt[1][2];i++)--R[1],++L[2],f[R[1]][1].push_back(mkp(L[2],2)),f[L[2]][2].push_back(mkp(R[1],1));
	for(int i=0;i<cnt[2][3];i++)--R[2],--R[3],f[R[2]][2].push_back(mkp(R[3],3)),f[R[3]][3].push_back(mkp(R[2],2));
	for(int i=0;i<cnt[0][3];i++)--R[0],++L[3],f[R[0]][0].push_back(mkp(L[3],3)),f[L[3]][3].push_back(mkp(R[0],0));
	for(int i=0;i<cnt[0][2];i++)++L[0],++L[2],f[L[0]][0].push_back(mkp(L[2],2)),f[L[2]][2].push_back(mkp(L[0],0));
	for(int i=0;i<cnt[1][3];i++)++L[1],++L[3],f[L[1]][1].push_back(mkp(L[3],3)),f[L[3]][3].push_back(mkp(L[1],1));
	vector<pair<pii,pii> >rg,rf;
	for(int i=0;i<4;i++)for(int j=1;j<=((i&1)?m:n);j++)if(!vis[0][j][i]){
		v1.clear(),gotverg(j,i);
		vector<pii>tmp1=minshow(v1);
		int hsh1=gethash(tmp1);
		reverse(v1.begin(),v1.end());
		vector<pii>tmp2=minshow(v1);
		int hsh2=gethash(tmp2);
		if(hsh1>hsh2)swap(hsh1,hsh2);
		rg.push_back(mkp(mkp(hsh1,hsh2),mkp(j,i)));
	}
	for(int i=0;i<4;i++)for(int j=1;j<=((i&1)?m:n);j++)if(!vis[1][j][i]){
		v2.clear(),gotverf(j,i);
		vector<pii>tmp1=minshow(v2);
		int hsh1=gethash(tmp1);
		reverse(v2.begin(),v2.end());
		vector<pii>tmp2=minshow(v2);
		int hsh2=gethash(tmp2);
		if(hsh1>hsh2)swap(hsh1,hsh2);
		rf.push_back(mkp(mkp(hsh1,hsh2),mkp(j,i)));
	}
	if(rg.size()!=rf.size())outno();
	memset(vis,0,sizeof(vis));
	sort(rg.begin(),rg.end()),sort(rf.begin(),rf.end()); 
	for(int i=0;i<rg.size();i++){
		pair<pii,pii> p1=rg[i],p2=rf[i];
		if(p1.fi!=p2.fi)outno();
		v1.clear(),v2.clear();
		int xx=p1.se.fi,yy=p1.se.se,XX=p2.se.fi,YY=p2.se.se;
		gotverg(xx,yy),gotverf(XX,YY);
		v1=minshow(v1),v2=minshow(v2);
		int t1=gethash(v1),t2=gethash(v2);
		if(t1!=t2)reverse(v2.begin(),v2.end());
		v1=minshow(v1),v2=minshow(v2);
		for(int i=0;i<v1.size();i++){
			int x=v1[i].fi,y=v1[i].se;
			if(y==0)ans1[v2[i].fi]=x;
			if(y==1)ans2[v2[i].fi]=x;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans1[i]<<" ";cout<<"\n";
	for(int i=1;i<=m;i++)cout<<ans2[i]<<" ";
}