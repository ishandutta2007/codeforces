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
const int Maxn=1e6+2017;
long long mod;
long long fact[Maxn];
long long p[Maxn];
LL n,m,a,q;
long long qp(long long x,long long y){
	if (!y) return 1;
	if (y==1) return x;
	if (y%2==0){
		LL z=qp(x,y/2);
		return z*z%mod;
	}
	else{
		LL z=qp(x,y/2);
		return z*z%mod*x%mod;
	}
}
long long qp2(long long x,long long y){
	if (!y) return 1;
	if (y==1) return x;
	if (y%2==0){
		LL z=qp(x,y/2);
		return z*z%q;
	}
	else{
		LL z=qp(x,y/2);
		return z*z%q*x%q;
	}
}
long long inv(long long x){
	return qp(x,mod-2);
}
LL calc(LL x,LL y){
	LL now=1;
	for (LL i=1;;i++){
		//cout<<now<<endl;
		now*=x;
		now%=y;
		if (now==1) return i;
	}
}
LL c(LL x,LL y){
	if (!y || y==x) return 1;
	LL ret=fact[x];
	ret*=inv(fact[y]);
	ret%=mod;
	ret*=inv(fact[x-y]);
	ret%=mod;
	return ret;
}
int main(){

	cin>>n>>m>>a>>q;
	
	mod=calc(a,q);
	//cout<<mod<<endl;
	p[0]=1;
	for (int i=1;i<Maxn;i++){
		p[i]=p[i-1]*a;
		p[i]%=q;
	}
	fact[0]=1;
	for (int i=1;i<Maxn;i++){
		fact[i]=fact[i-1]*(LL)i;
		fact[i]%=mod;
	}
	LL pre=0;
	vector<LL> ans;
	for (int i=1;i<=n;i++){
		if (i<=m+1){
			pre+=c(m,i-1);
			//cout<<i<<' '<<c(m,i-1)<<endl;
			pre%=mod;
		}
		//cout<<pre<<endl;
		ans.push_back(p[pre]);
	}
	reverse(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++){
		printf("%I64d ",ans[i]);
	}
	printf("\n");
}