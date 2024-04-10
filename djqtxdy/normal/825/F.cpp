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
const int Maxn=8005;
int fail[Maxn][Maxn];
int dp[Maxn];
int pre[Maxn];
void getf(string kk){
	for (int i=0;i<kk.length();i++){
		string s=kk.substr(i);
		for(int j=1;j<s.length();j++){
	        int k=fail[i][j];
	        while(k && s[j]!=s[k]) k=fail[i][k];
	        fail[i][j+1]=(s[j]==s[k])?k+1:0;
	    }
	}
}
int g(int x){
	int ret=0;
	while (x){
		ret++;
		x/=10;
	}
	return ret;
}
int main(){
	//freopen("decomp.in","r",stdin);
	//freopen("decomp.out","w",stdout);
	string x;
	cin>>x;
	getf(x);
	dp[1]=2;
	for (int i=2;i<=x.length();i++){
		dp[i]=1e9;
		for (int j=0;j<i;j++){
			//j+1~i
			int val=fail[j][i-j];
			if (val*2>=i-j && (i-j)%(i-j-val)==0){
				int len=i-j-val;
				int t=(i-j)/len;
				if (dp[j]+len+g(t)<dp[i]){
					dp[i]=dp[j]+len+g(t);
				}
			}
			else{
				int len=i-j;
				int t=(i-j)/len;
				if (dp[j]+len+g(t)<dp[i]){
					dp[i]=dp[j]+len+g(t);
				}
			}
		}
	}
	printf("%d\n",dp[(int)x.length()]);
}