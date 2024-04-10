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
/*
cost=a[i]-a[j];
cost_of_chain=cost 
dp[i][j][i] =dp[i-1][j-cost][l]
dp[i][j][k] = dp[i-1][j][k];
. . . .     . . . . . . . . 
*/
const int Maxn=205;
const int Maxm=1005;
const long long mod=1e9+7;
LL dp[Maxn][105][Maxm];
int cost[Maxn][Maxn];
int a[Maxn];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	// f=0: normal f=1: min f=2:max;
	//dp[1][1][0]=1;
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=n/2+1;j++){
			for (int Co=0;Co<=k;Co++){
				int leng=a[i]-a[i-1];
				//dp[i][j][Co]+=dp[i-1][j][Co];
				if (Co>=leng*j)dp[i][j][Co]+=dp[i-1][j][Co-leng*j]*(j+1);
				dp[i][j][Co]%=mod;
				if (Co>=leng*(j-1) && j){
					dp[i][j][Co]+=dp[i-1][j-1][Co-leng*(j-1)];
				}dp[i][j][Co]%=mod;
				if (Co>=leng*(j+1)){
					dp[i][j][Co]+=dp[i-1][j+1][Co-leng*(j+1)]*(j+1);
				}dp[i][j][Co]%=mod;
				//cout<<leng<<' '<<i<<' '<<j<<' '<<Co<<' '<<dp[i][j][Co]<<endl;
			}
		}
		//cout<<endl;
	}
	long long ans=0;
	for (int j=0;j<=k;j++){
		ans+=dp[n][0][j];
		ans%=mod;
	}
	printf("%I64d\n",ans);
	return 0;
}
/*
1-2-3-2
1-2-1
1-2-1-3
*/
/*w12+2*w23=3
2*w12=4
2*w12+w13=1
*/