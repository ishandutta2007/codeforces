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
string a[55];
bool f[55];
string ans[55];
int now;
string g(){
	string s="";
	s+=(now/26+'A');
	s+=(now%26+'a');now++;
	return s;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n-m+1;i++){
		cin>>a[i];
		if (a[i]=="NO") f[i]=false; else f[i]=true;
	}
	if (f[0]){
		ans[0]=g();
		ans[1]=g();
	}
	else{
		ans[0]=g();
		ans[1]=ans[0];
	}
	for (int i=2;i<m;i++){
		ans[i]=g();
	}
	for (int i=m;i<n;i++){
		if (f[i-m+1]){
			ans[i]=g();
		}
		else{
			ans[i]=ans[i-m+1];
		}
	}
	for (int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
}