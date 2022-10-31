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
const int Maxn=5005;
long long dp[Maxn][Maxn];
int a[Maxn*60];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ss=n/k,sl=ss+1;
	int amts=k-(n%k),amtl=n%k;
	assert(ss*amts+sl*amtl==n);
	dp[0][0]=0;
	for (int i=0;i<=amts;i++){
		for (int j=0;j<=amtl;j++){
			if (!i && !j) continue;
			dp[i][j]=1e18;
			int len=i*ss+j*sl;
			if (i){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a[len]-a[len-ss+1]);
			}
			if (j){
				dp[i][j]=min(dp[i][j],dp[i][j-1]+a[len]-a[len-sl+1]);
			}
		}
	}
	printf("%I64d\n",dp[amts][amtl]);
}