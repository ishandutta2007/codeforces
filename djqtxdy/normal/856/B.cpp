//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
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
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
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

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=1e6+5;
const long long mod=1e10+7;
const long long mult=20160116;
int ccc;
vector<int> G[Maxn];
struct node{
	node* nxt[27];
	int siz;
	int number;
	long long H1,H2;
	node(){
		number=++ccc;
		for (int i=0;i<26;i++) nxt[i]=NULL;
		siz=0;
	}
};
node* root;
char c[Maxn];
void A(int len){
	long long nh1=0LL,nh2=0LL;
	node* now=root;
	for (int i=0;i<len;i++){
		int pos=c[i]-'a';
		nh1*=mult;
		nh1+=pos;
		nh1%=mod;
		if (i){
			nh2*=mult;
			nh2+=pos;
			nh2%=mod;
		}
		
		if (now->nxt[pos]==NULL){
			now->nxt[pos]=new node;
		}
		now=now->nxt[pos];
		now->H1=nh1;
		now->H2=nh2;
	}
}
int process(){
	vector<pair<long long,int> > now;
	vector<node* > nodes,New;
	nodes.push_back(root);
	while (!nodes.empty()){
		New.clear();
		for (int i=0;i<nodes.size();i++){
			for (int j=0;j<26;j++){
				if (nodes[i]->nxt[j]){
					New.push_back(nodes[i]->nxt[j]);
				}
			}
		}
		nodes=New;
		for (int i=0;i<nodes.size();i++){
			int pos=lower_bound(now.begin(),now.end(),mp(nodes[i]->H2,-1))-now.begin();
			if (pos==now.size()) continue;
			if (now[pos].first==nodes[i]->H2){
				G[now[pos].second].push_back(nodes[i]->number);
				//cout<<now[pos].second<<' ' <<nodes[i]->number<<endl;
			}
		}
		now.clear();
		for (int i=0;i<nodes.size();i++){
			now.pb(mp(nodes[i]->H1,nodes[i]->number));
		}
		sort(now.begin(),now.end());
	}
}
int dp[Maxn];
bool isr[Maxn];
void dfs(int x){
	int M1=0,M2=1;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		dfs(v);
		M1+=dp[v];
		for (int j=0;j<G[v].size();j++){
			M2+=dp[G[v][j]];
		}
	}
	dp[x]=max(M1,M2);
}
void solve(){
	ccc=0;
	root=NULL;
	root=new node;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",c);
		int k=strlen(c);
		//reverse(c,c+k);
		//printf("%s\n",c);
		A(k);
	}
	for (int i=1;i<=ccc;i++) G[i].clear();
	//cerr<<root->siz<<endl;
	process();
	for (int i=1;i<=ccc;i++) isr[i]=true;
	for (int i=1;i<=ccc;i++){
		for (int j=0;j<G[i].size();j++){
			isr[G[i][j]]=false;
		}
	}
	for (int i=1;i<=ccc;i++) dp[i]=0;
	int ans=0;
	for (int i=2;i<=ccc;i++){
		if (isr[i]){
			dfs(i);
			ans+=dp[i];
		}
	}
	//cout<<ccc<<endl;
	printf("%d\n",ans);
	return ;
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		solve(); 
	}
}