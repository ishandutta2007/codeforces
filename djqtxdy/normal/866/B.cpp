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
#include <assert.h>
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
const int Maxn=1e5+5;
int s[Maxn],a[Maxn],b[Maxn];
long long tot,ans;
set<int> avail;
int main(){
	int n,S;
	scanf("%d %d",&n,&S);
	long long now=0,ncnt=0;
	priority_queue<pair<int,int> > q,qq;
	for (int i=0;i<n;i++){
		scanf("%d %d %d",&s[i],&a[i],&b[i]);
		tot+=s[i];
		now+=1ll*s[i]*b[i];
		if (a[i]>=b[i]) q.push(mp(-a[i]+b[i],s[i])),ncnt+=s[i],now+=1ll*s[i]*(a[i]-b[i]);
		else qq.push(mp(a[i]-b[i],s[i]));
	}
	//cout<<now<<endl;
	ans=(tot+S-1)/(LL)S;
	// a
	long long del=0,tt=ncnt,aa=0;
	for (;ncnt>=0;del++,ncnt--){
		if ((ncnt+S-1)/(LL)S+(tot-ncnt+S-1)/(LL)S<=ans) break;
	}
	ncnt=tt;
	for (;;aa++,ncnt++){
		if ((ncnt+S-1)/(LL)S+(tot-ncnt+S-1)/(LL)S<=ans) break;
	}
	long long tmp=now;
	while (!q.empty()){
		pair<int,int> x=q.top();
		q.pop();
		if (x.second<del){
			del-=x.second;
			now+=1ll*x.second*x.first;
		} 
		else{
			now+=1ll*del*x.first;
			break;
		}
	}
	while (!qq.empty()){
		pair<int,int> x=qq.top();
		qq.pop();
		if (x.second<aa){
			aa-=x.second;
			tmp+=1ll*x.second*x.first;
		} 
		else{
			tmp+=1ll*aa*x.first;
			break;
		}
	}
	printf("%I64d\n",max(now,tmp));
	return 0;
}