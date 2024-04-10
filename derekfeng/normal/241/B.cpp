#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M=1e9+7;
const int N=5e4+4,S=1.6e6+4;
int a[N],n,tot=1;
vector<int>vec[S];
int sz[S],ch[S][2],ds[30];
ll m;vector<pii>v,nv;
int ans,res;
void ins(int i,int d,int x){
	sz[i]++,vec[i].push_back(x);
	if(d<0)return;
	int s=x>>d&1;
	if(!ch[i][s])ch[i][s]=++tot;
	ins(ch[i][s],d-1,x);
}
void calc(int a,int b){
	if(!a||!b)return;
	int all=vec[a].size();
	memset(ds,0,120);
	for(auto x:vec[a])
		for(int j=0;j<30;j++)
			ds[j]+=x>>j&1;
	for(auto x:vec[b])
		for(int j=0;j<30;j++){
			int v=(x>>j&1)?all-ds[j]:ds[j];
			(ans+=(ll)(1<<j)*v%M)%=M;
		}
}
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),ins(1,29,a[i]);
	v.push_back({1,1});
	for(int i=29;~i;i--){
		nv.clear();ll nm=m;
		for(auto[a,b]:v){
			nm-=(ll)sz[ch[a][0]]*sz[ch[b][1]];
			if(a!=b)nm-=(ll)sz[ch[a][1]]*sz[ch[b][0]];
		}
		if(nm<=0){
			res|=(1<<i);
			for(auto[a,b]:v){
				if(ch[a][0]&&ch[b][1])
					nv.push_back({ch[a][0],ch[b][1]});
				if(a!=b&&ch[a][1]&&ch[b][0])
					nv.push_back({ch[a][1],ch[b][0]});
			}
		}else{
			m=nm;
			for(auto[a,b]:v){
				calc(ch[a][0],ch[b][1]);
				if(a!=b)calc(ch[a][1],ch[b][0]);
				if(ch[a][0]&&ch[b][0])
					nv.push_back({ch[a][0],ch[b][0]});
				if(ch[a][1]&&ch[b][1])
					nv.push_back({ch[a][1],ch[b][1]});
			}
		}
		v=nv;
	}
	printf("%d",(ans+m%M*res)%M);
}