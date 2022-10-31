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
//orz mqy
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
const int Maxm=27;
int a[Maxm];
int n;
char s[Maxn];
long long dp1[Maxn];
int dp2[Maxn];
int res;
bool occ[Maxm];
const long long mod=1000000007;
bool check(int len){
	for (int i=0;i<26;i++){
		if (occ[i]){
			if (a[i]<len) return false;
		}
	}
	return true;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=0;i<26;i++){
		scanf("%d",&a[i]);
	}
	dp1[0]=1;
	for (int i=1;i<=n;i++){
		dp2[i]=1000000;
	}
	dp2[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++){
			occ[j]=false;
		}
		for (int j=i-1;j>=0;j--){
			occ[s[j+1]-'a']=true;
			if (check(i-j)){
				dp1[i]+=dp1[j];
				dp1[i]%=mod;
				dp2[i]=min(dp2[i],dp2[j]+1);
				res=max(res,i-j);
			}
			else{
				break;
			}
		}
	}
	printf("%I64d\n%d\n%d",dp1[n],res,dp2[n]);
	return 0;
}
/*
108
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
8 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/