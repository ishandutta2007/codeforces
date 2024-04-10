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
const int Maxn=1005;
long long siz[Maxn],maxf[Maxn],minf[Maxn];
pair<int,pair<int,int> > d[Maxn];
vector<int> G[Maxn],v[Maxn];
bool f[Maxn];
bool vis[Maxn];
long long dist(int u,int v){
	long long k1=abs(d[u].second.first-d[v].second.first);
	long long k2=abs(d[u].second.second-d[v].second.second);
	return (LL)k1*k1+k2*k2;
}
void dfs(int u,int dd,LL &res){
	vis[u]=true;
	for (int i=0;i<G[u].size();i++){
		int v=G[u][i];
		dfs(v,dd+1,res);
	}
	if (dd==0 || dd%2==1){
		res+=(LL)d[u].first*d[u].first;
	}
	else{
		res-=(LL)d[u].first*d[u].first;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d %d %d",&d[i].second.first,&d[i].second.second,&d[i].first);
	}
	sort(1+d,1+d+n);
	reverse(d+1,1+d+n);
	//for (int i=1;i<=n;i++) cout<<d[i].first<<endl;
	memset(f,false,sizeof(f));
	for (int i=1;i<=n;i++){
		for (int j=i-1;j>=1;j--){
			 LL tmp=dist(i,j);
			 LL tmp2=d[i].first+d[j].first;
			 tmp2=tmp2*tmp2;
		//	cout<<i<<' '<<j<<' '<<tmp<<' '<<tmp2<<endl;
			 if (tmp2>tmp){
			 	//cout<<i<<j<<endl;
			 	G[j].push_back(i);
			 	break;
			 }
		}
	}
	long long ans=0;
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++){
		if (!vis[i]) dfs(i,0,ans); 
	}
	//3.1415926535898
	double res=ans*(long double)3.1415926535898;
	printf("%.15lf\n",res);
	return 0;
}