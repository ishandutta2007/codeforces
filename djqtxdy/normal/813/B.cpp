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
LL M=3e18;
vector<long long> v1,v2,v3;
int main (){
	long long x,y,l,r;
	scanf("%I64d %I64d %I64d %I64d",&x,&y,&l,&r);
	LL now=1;
	for (;;){
		v1.pb(now);
		if (M/x>now){
			now*=x;
		}
		else break;
	}
	now=1;
	for (;;){
		v2.pb(now);
		if (M/y>now){
			now*=y;
		}
		else break;
	}
	for (int i=0;i<v1.size();i++){
		for (int j=0;j<v2.size();j++){
			v3.pb(v1[i]+v2[j]);
		}
	}
	v3.pb(l-1);
	v3.pb(r+1);
	sort(v3.begin(),v3.end());
	LL anss=0LL;
	for (int i=0;i<v3.size()-1;i++){
		if (v3[i]>=l-1 && v3[i+1]<=r+1) anss=max(anss,v3[i+1]-v3[i]-1);
	}
	printf("%I64d\n",anss);
	return 0;
}