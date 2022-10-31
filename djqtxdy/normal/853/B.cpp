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
const int Maxn=1000005;
vector<pair<int,int> > S[Maxn],T[Maxn];
vector<int> prem[Maxn],sufm[Maxn];
int pointp[Maxn],points[Maxn];
vector<pair<int,int>  > event[Maxn];
long long nowans[Maxn];
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int d,f,t,c;
		scanf("%d %d %d %d",&d,&f,&t,&c);
		if (f==0){
			d--;
			T[t].push_back(mp(d,c));
			event[d].push_back(mp(1,t));
		}
		else{
			d++;
			S[f].pb(mp(d,c));
			event[d].push_back(mp(0,f));
		}
	}
	for (int i=1;i<=n;i++){
		sort(S[i].begin(),S[i].end());
		sort(T[i].begin(),T[i].end());
		if (!S[i].empty()){
			int nn=S[i].size();
			prem[i].resize(nn);
			prem[i][0]=S[i][0].second;
			for (int j=1;j<nn;j++){
				prem[i][j]=min(prem[i][j-1],S[i][j].second);
			}
		}
		if (!T[i].empty()){
			int nn=T[i].size();
			sufm[i].resize(nn);
			sufm[i][nn-1]=T[i][nn-1].second;
			for (int j=nn-2;j>=0;j--){
				sufm[i][j]=min(sufm[i][j+1],T[i][j].second);
			}
		}
	}
	long long res=1e18;
	long long totans=0;
	{
		int st=0,ed=k-1;
		memset(pointp,-1,sizeof(pointp));
		memset(points,-1,sizeof(points));
		for (int i=1;i<=n;i++){
			for (int j=0;j<T[i].size();j++){
				//T[i][j]
				if (T[i][j].first>=ed){
					pointp[i]=j;
					break;
				}
			}
			if (pointp[i]==-1) pointp[i]=T[i].size();
			if (points[i]<0 || pointp[i]>=T[i].size()){
				nowans[i]=1e12;
			}
			else{
				nowans[i]=prem[i][points[i]]+sufm[i][pointp[i]];
				
			}
			totans+=nowans[i];
		}
	}
	
	res=min(res,totans);
	for (int st=1;st<Maxn;st++){
		int ed=st+k-1;
		if (ed>1e6) break;
		vector<int> occ;
		for (int i=0;i<event[st].size();i++){
			if (event[st][i].first==0){
				occ.pb(event[st][i].second);
				points[event[st][i].second]++;
			}
		}
		for (int i=0;i<event[ed-1].size();i++){
			if (event[ed-1][i].first==1){
				occ.pb(event[ed-1][i].second);
				pointp[event[ed-1][i].second]++;
			}
		}
		for (int ii=0;ii<occ.size();ii++){
			int i=occ[ii];
			LL ne;
			if (points[i]<0 || pointp[i]>=T[i].size()){
				ne=1e12;
			}
			else{
				ne=prem[i][points[i]]+sufm[i][pointp[i]];
				
			}
			totans+=ne;
			totans-=nowans[i];
			nowans[i]=ne;
		}
		res=min(res,totans);
	}
	if (res<1e12){
		printf("%I64d\n",res);
	}
	
	else{
		printf("-1\n");
	}
	return 0;
}