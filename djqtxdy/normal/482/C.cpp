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
const int Maxn=55;
const int Maxm=25;
const int Maxmsk=1e6+1e5;
int n,m;
char c[Maxn][Maxm];
long long No[Maxmsk];
double f[Maxmsk];
int dig(long long x){
	int ret=0;
	for (int i=0;i<60;i++){
		if (x>>(LL)i&1) ret++;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",c[i]);
	}
	m=strlen(c[0]);
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			int d=0;
			for (int pos=0;pos<m;pos++){
				if (c[i][pos]==c[j][pos]) d|=(1<<pos);
			}
			No[d]|=(1LL<<i);
			No[d]|=(1LL<<j);
		}
	}
	for (int i=(1<<m)-1;i>=0;i--){
		for (int j=0;j<m;j++){
			if (!(i>>j&1)){
				No[i]|=No[i^(1<<j)];
			}
		}
		int tot=0;
		for (int j=0;j<m;j++){
			if (!(i>>j&1)) f[i]+=f[i^(1<<j)],tot++; 
		}
		if (tot!=0) f[i]/=(double)tot;
		f[i]+=(double)((double)dig(No[i])/(double)n);
	}
	printf("%.15lf",f[0]);
	return 0;
}