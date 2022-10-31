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
const int Maxn=205;
long long a[Maxn];
int s2[Maxn],s5[Maxn];
int dp[2][Maxn][Maxn*25];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		LL tmp=a[i];
		while (tmp%2==0) s2[i]++,tmp/=2;
		while (tmp%5==0) s5[i]++,tmp/=5;
	//	cout<<s2[i]<<' '<<s5[i]<<endl;
	}
	for (int i=0;i<2;i++){
		for (int j=0;j<Maxn;j++){
			for (int k=0;k<Maxn*25;k++) dp[i][j][k]=-1e9;
		}
	}
	dp[0][0][0]=0;
	for (int ii=1;ii<=n;ii++){
		int i=ii%2;
		for (int j=0;j<=k;j++){
			for (int l=0;l<Maxn*25;l++){
				dp[i][j][l]=dp[1-i][j][l];
				//if (i==1 && j==1 && l==s5[ii]) cerr<<dp[0][0][0];
				if (j && l>=s5[ii] && dp[1-i][j-1][l-s5[ii]]!=-1e9) dp[i][j][l]=max(dp[i][j][l],dp[1-i][j-1][l-s5[ii]]+s2[ii]);
			}
		}
		//cout<<dp[i][1][2]<<endl;
	}
	int ans=0;
	for (int i=0;i<Maxn*25;i++){
		ans=max(ans,min(i,dp[n%2][k][i]));
		//cout<<i<<' '<<dp[n%2][k][i]<<endl;
	}
	printf("%d\n",ans);
	return 0;
}