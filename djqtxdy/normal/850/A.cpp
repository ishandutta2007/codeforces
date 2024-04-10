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
const int Maxn=1005;
int a[Maxn],b[Maxn],c[Maxn],d[Maxn],e[Maxn];
int aa[Maxn][Maxn],bb[Maxn][Maxn],cc[Maxn][Maxn],dd[Maxn][Maxn],ee[Maxn][Maxn];
int main(){
	double pi=acos(-1);
	//cout<<pi<<endl;
	//return 0;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i]);
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			aa[i][j]=a[i]-a[j];
			bb[i][j]=b[i]-b[j];
			cc[i][j]=c[i]-c[j];
			dd[i][j]=d[i]-d[j];
			ee[i][j]=e[i]-e[j];
		}
	}
	vector<int> ans;
	for (int i=0;i<n;i++){
		bool flag=true;
		for (int j=0;j<n;j++){
			if (i==j) continue;
			for (int k=j+1;k<n;k++){
				if (k==i) continue;
				//i,j && i,k;
				int xx=aa[i][j]*aa[i][k]+bb[i][j]*bb[i][k]+cc[i][j]*cc[i][k]+dd[i][j]*dd[i][k]+ee[i][j]*ee[i][k];
				double yy=sqrt((aa[i][j]*aa[i][j])+(bb[i][j]*bb[i][j])+(cc[i][j]*cc[i][j])+(dd[i][j]*dd[i][j])+(ee[i][j]*ee[i][j]))*sqrt((aa[i][k]*aa[i][k])+(bb[i][k]*bb[i][k])+(cc[i][k]*cc[i][k])+(dd[i][k]*dd[i][k])+(ee[i][k]*ee[i][k]));
				double zz=1.0*xx/yy;
				double zzz=acos(zz);
				zzz/=pi;
				zzz*=180;
				//cout<<zzz<<endl;
				if (zzz<90.0){
					flag=false;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) ans.pb(i+1);
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}