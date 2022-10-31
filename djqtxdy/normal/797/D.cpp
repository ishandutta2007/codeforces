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
const int Maxn=100005;
int v[Maxn],l[Maxn],r[Maxn];
bool hav[Maxn];
bool vis[Maxn];
void go(int u,int lo,int hi){
	if (u==-1) return;
	if (lo>hi) return;
	vis[u]=true;
	if (v[u]<lo || v[u]>hi) vis[u]=false;
	go(l[u],lo,min(hi,v[u]-1));
	go(r[u],max(lo,v[u]+1),hi);
}
map<int,int> lll;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d %d %d",&v[i],&l[i],&r[i]);
		hav[l[i]]=true;
		hav[r[i]]=true;
	}
	int root;
	for (int i=1;i<=n;i++){
		if (!hav[i]) root=i;
	}
	go(root,0,INF);
	int ans=0;
	for (int i=1;i<=n;i++){
		if (vis[i]){
			lll[v[i]]=1;
		}
	}
	for (int i=1;i<=n;i++){
		if (!lll.count(v[i])){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}