#include<bits/stdc++.h>
#define int long long
const int N=800005,base=998244353,mod=19260817;
using namespace std;

int n,m,s;
const int P[]={114,514,1919,810,114514,1919810};

void il(){cout<<"No solution",exit(0);} 

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

int cnt[6];//UL,LD,DR,RU,UD,LR
struct graph{
	#define _to e[i].to
	#define fore(k) for(int i=hd[k];i;i=e[i].nx)
	struct edge{
	    int to,nx;
	}e[N];int hd[N],S;
	void add(int fr,int to){
	    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
	    e[++S]=(edge){fr,hd[to]},hd[to]=S;
	}
	int c[N],v[N];
	vector<pair<int,vector<int>>> A;
	vector<int> a; 
	void dfs(int k){
		a.push_back(k),v[k]=1;
		fore(k)if(!v[_to])dfs(_to);
	}
	void get_hash(){
		for(int i=1;i<=s;i++){
			if(v[i])continue;a.clear();
			dfs(i);
			vector<int> ans={base,0,0};
			int nw=0,E=gsc(base,a.size());
			for(int j=0;j<a.size();j++)
				nw=(nw*base+P[c[a[j]]])%mod;
		//	for(auto x:a)cout<<c[x]<<' ';cout<<endl;
			for(int j=0;j<a.size();j++){
				nw=((nw*base-E*P[c[a[j]]]+P[c[a[j]]])%mod+mod)%mod;
				ans=min(ans,{nw,1,j});
			}
			nw=0;reverse(a.begin(),a.end());
			for(int j=0;j<a.size();j++)
				nw=(nw*base+P[c[a[j]]])%mod;
			for(int j=0;j<a.size();j++){
				nw=((nw*base-E*P[c[a[j]]]+P[c[a[j]]])%mod+mod)%mod;
				ans=min(ans,{nw,0,j});
			}
			if(ans[1])reverse(a.begin(),a.end());
			vector<int>na;
			for(int j=ans[2],i=0;i<a.size();i++,j++,j%=a.size())
				na.push_back(a[j]);
			A.push_back({ans[0],na});
			//for(auto x:na)cout<<c[x]<<' ';cout<<endl;
		}
		sort(A.begin(),A.end());//cout<<endl;
	}
}A,B;

int id[N],ct,Id[N];
pair<int,int> E1[N],E2[N];
int R[N],C[N];
int gp(char c,int k){
	if(c=='R')k+=m;
	if(c=='B')k+=m+n;
	if(c=='L')k+=m+n+m;
	return k;
}
auto dp(int k){
	if(k<=m)return make_pair('T',k);
	if(k<=m+n)return make_pair('R',k-m);
	if(k<=m+n+m)return make_pair('B',k-m-n);
	return make_pair('L',k-m-n-m);
}
void chk(pair<int,int>&x){if(x.first>x.second)swap(x.first,x.second);}

void input(){
	cin>>n>>m;s=n+m;
	for(int i=1;i<=n+m;i++){
		char x,y;int a,b;cin>>x>>y>>a>>b;
		id[gp(x,a)]=id[gp(y,b)]=i;
		E1[i]={gp(x,a),gp(y,b)};
		chk(E1[i]);
		if(x+y=='T'+'L')cnt[0]++,A.c[i]=0;
		if(x+y=='B'+'L')cnt[1]++,A.c[i]=1;
		if(x+y=='B'+'R')cnt[2]++,A.c[i]=2;
		if(x+y=='T'+'R')cnt[3]++,A.c[i]=3;
		if(x+y=='T'+'B')cnt[4]++,A.c[i]=4;
		if(x+y=='R'+'L')cnt[5]++,A.c[i]=5;
	}
	if(cnt[4]&&cnt[5])il();
	int c=0;
	for(int i=1;i<=cnt[0];i++)++c,B.c[c]=0,Id[gp('T',i)]=Id[gp('L',i)]=c,E2[c]={gp('T',i),gp('L',i)};
	for(int i=1;i<=cnt[1];i++)++c,B.c[c]=1,Id[gp('B',i)]=Id[gp('L',n-i+1)]=c,E2[c]={gp('B',i),gp('L',n-i+1)};
	for(int i=1;i<=cnt[2];i++)++c,B.c[c]=2,Id[gp('B',m-i+1)]=Id[gp('R',n-i+1)]=c,E2[c]={gp('B',m-i+1),gp('R',n-i+1)};
	for(int i=1;i<=cnt[3];i++)++c,B.c[c]=3,Id[gp('T',m-i+1)]=Id[gp('R',i)]=c,E2[c]={gp('T',m-i+1),gp('R',i)};
	for(int i=1;i<=cnt[4];i++)++c,B.c[c]=4,Id[gp('T',i+cnt[0])]=Id[gp('B',i+cnt[1])]=c,E2[c]={gp('T',i+cnt[0]),gp('B',i+cnt[1])};
	for(int i=1;i<=cnt[5];i++)++c,B.c[c]=5,Id[gp('L',i+cnt[0])]=Id[gp('R',i+cnt[3])]=c,E2[c]={gp('L',i+cnt[0]),gp('R',i+cnt[3])};
	for(int i=1;i<=n+m;i++)chk(E2[i]);
	for(int i=1;i<=n;i++){
		A.add(id[gp('L',i)],id[gp('R',i)]);
		B.add(Id[gp('L',i)],Id[gp('R',i)]);
	}
	for(int i=1;i<=m;i++){
		A.add(id[gp('T',i)],id[gp('B',i)]);
		B.add(Id[gp('B',i)],Id[gp('T',i)]);
	}
}

void calc(){
	A.get_hash(),B.get_hash();
	if(A.A.size()!=B.A.size())il();
	int nl=A.A.size();
	for(int i=0;i<nl;i++){
		int x=A.A[i].first,y=B.A[i].first;
		auto X=A.A[i].second,Y=B.A[i].second;
		if(x!=y)il();
		if(X.size()!=Y.size())il();
		for(int j=0;j<X.size();j++){
			auto a=dp(E1[X[j]].first),b=dp(E2[Y[j]].first);
			if(a.first!=b.first)il();
			if(a.first=='T'||a.first=='B')
				C[b.second]=a.second;
			else 
				R[b.second]=a.second;
			a=dp(E1[X[j]].second),b=dp(E2[Y[j]].second);
			if(a.first!=b.first)il();
			if(a.first=='T'||a.first=='B')
				C[b.second]=a.second;
			else 
				R[b.second]=a.second;
		}
	}
	for(int i=1;i<=n;i++)cout<<R[i]<<" ";cout<<endl;
	for(int i=1;i<=m;i++)cout<<C[i]<<" ";
}

void solve(){
	input();
	calc();
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}