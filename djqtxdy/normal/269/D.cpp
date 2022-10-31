#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
const int Maxn=200005;
const LL mod=5220160116; 
int n,t;
map<int,int> to;
int from[Maxn*3];
struct panel{
	int height,lf,rg;
}p[Maxn];
set<pair<int,int> > rp,lp;
bool cmp(panel a,panel b){
	return a.height>b.height;
}
vector<int> G[Maxn];
int tag[Maxn*4];
int tree[Maxn*4];
void Push(int p){
	if (tag[p]==-1) return;
	tag[p*2]=tag[p*2+1]=tag[p];
	tree[p*2]=tree[p*2+1]=tree[p];
	tag[p]=-1;
}
void Ct(int p,int l,int r){
	tag[p]=-1;
	tree[p]=-1;
	if (l==r) return;
	int mid=(l+r)>>1;
	Ct(p*2,l,mid);
	Ct(p*2+1,mid+1,r);
}
void modify(int p,int l,int r,int lo,int hi,int val){
//cout<<p<<l<<r<<endl;
	if (lo<=l && r<=hi){
		tag[p]=val;
		tree[p]=val;
		return;
	}
	Push(p);
	int mid=(l+r)>>1;
	if (lo<=mid){
		modify(p*2,l,mid,lo,min(hi,mid),val);
	}
	if (hi>mid){
		modify(p*2+1,mid+1,r,max(lo,mid+1),hi,val);
	}
	tree[p]=max(tree[p*2],tree[p*2+1]);
}
int query(int p,int l,int r,int x){
	//cout<<p<<l<<r<<endl;
	if (tag[p]!=-1) return tag[p];
	int mid=(l+r)>>1;
	if (x<=mid){
		return query(p*2,l,mid,x);
	}
	else{
		return query(p*2+1,mid+1,r,x);
	}
}
int mqy(int p,int l,int r,int lo,int hi){ // max_query(mqy)
	if (lo<=l && r<=hi){
		return tree[p];
	}
	//if (tag[p]!=-1) return tag[p]; 
	Push(p);
	int mid=(l+r)>>1;
	int ans=-1;
	if (lo<=mid){
		ans=max(ans,mqy(p*2,l,mid,lo,min(mid,hi)));
	}
	if (hi>mid){
		ans=max(ans,mqy(p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	return ans;
}
int dp[Maxn];
int ncnt=0;
bool lst[Maxn];
bool check(int x,int y){
	if (x==-1) return false;
	int lo=max(p[x].lf,p[y].lf),hi=min(p[x].rg,p[y].rg);
	
	int qq=mqy(1,1,ncnt,lo,hi-1);//if (x==0 && y==4) cout<<lo<<hi<<qq<<endl;
	return qq==x;
} 
void construct(bool flag){
	//l->r-1;
	Ct(1,1,n);
	for (int i=0;i<n;i++){
		int l=p[i].lf,r=p[i].rg;
		int val1=mqy(1,1,ncnt,l,l);
		int val2=mqy(1,1,ncnt,r-1,r-1);
		if (check(val1,i)){
			if (!flag) {
				G[i].pb(val1);
			//	cerr<<"construct"<<i<<' '<<val1<<endl;
			}
			else{
				G[n-val1-1].pb(n-i-1);
			//	cerr<<"construct"<<n-val1-1<<' '<<n-i-1<<endl;
			}
		}
		if (check(val2,i)){
			if (!flag) {
				G[i].pb(val2);
			//	cerr<<"construct"<<i<<' '<<val2<<endl;
			}
			else{
				G[n-val2-1].pb(n-i-1);
			//	cerr<<"construct"<<n-val2-1<<' '<<n-i-1<<endl;
			}
		}
		modify(1,1,ncnt,l,r-1,i);
		//cerr<<"UPDATE:"<<l<<' '<<r<<' '<<i<<' '<<mqy(1,1,ncnt,1,ncnt)<<endl;
	}
	
}
int main(){
	memset(tag,-1,sizeof(tag));
	scanf("%d %d",&n,&t);
	for (int i=1;i<=n;i++){
		scanf("%d %d %d",&p[i].height,&p[i].lf,&p[i].rg);
		to[p[i].lf]=0;
		to[p[i].rg]=0;
	}
	
	
	
	
	to[1e9]=0;
	to[-1e9]=0;
	p[0].height=t;
	p[0].lf=-1e9;
	p[0].rg=1e9;
	//p[n+1]={0,-1e9,1e9};
	p[n+1].height=0;
	p[n+1].lf=-1e9;
	p[n+1].rg=1e9;
	n+=2;
	sort(p,p+n,cmp);
	for (map<int,int>::iterator it=to.begin();it!=to.end();it++){
		it->second=++ncnt;
		from[ncnt]=it->first;
	}
	for (int i=0;i<n;i++){
		p[i].lf=to[p[i].lf];
		p[i].rg=to[p[i].rg];
		//cout<<i<<' '<<from[p[i].lf]<<' '<<from[p[i].rg]<<endl;
	}
	
	
	
	
	
	construct(false);
	reverse(p,p+n);
	construct(true);
	reverse(p,p+n);
	dp[0]=2e9;
	for (int i=0;i<n;i++){
		p[i].lf=from[p[i].lf];
		p[i].rg=from[p[i].rg];
		//cout<<i<<' '<<p[i].lf<<' '<<p[i].rg<<endl;
	}
	for (int i=1;i<n;i++){
		for (int j=0;j<G[i].size();j++){
			int v=G[i][j];
			//cout<<"edge:"<<v<<' '<<i<<' '<<min(from[p[v].rg],from[p[i].rg])<<' '<<max(from[p[v].lf],from[p[i].lf])<<endl;
			dp[i]=max(dp[i],min(dp[v],min(p[v].rg,p[i].rg)-max(p[v].lf,p[i].lf)));
		}
		//cout<<dp[i]<<endl;
	}
	int ans=0;
	printf("%d\n",dp[n-1]);
	return 0;
} 
/*
3 4
1 1 3
2 0 1
3 1 3
*/ 
/*
5 6
4 1 6
3 2 7
5 9 11
3 10 15
1 13 16
*/