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
const int Maxn=51;
string s[Maxn];
int cost[Maxn];
int p[Maxn];
vector<pii > x,y,z;
int n,m;
int m1=100,m2=100,m3=100;
int main(){
	
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		cin>>s[i];
		for (int j=0;j<m;j++){
			if (s[i][j]>='0' && s[i][j]<='9'){
				x.push_back(mp(i,j));
			}
			else if (s[i][j]>='a' && s[i][j]<='z'){
				y.push_back(mp(i,j));
			}
			else{
				z.pb(mp(i,j));
			}
		}
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	sort(z.begin(),z.end());
	int MIN=75;
	for (int i=0;i<x.size();i++){
		m1=min(m-x[i].second,x[i].second);
		for (int j=0;j<y.size();j++){
			m2=min(m-y[j].second,y[j].second);
			if (x[i].first==y[j].first){
				continue;
			}
			for (int k=0;k<z.size();k++){
				m3=min(m-z[k].second,z[k].second);
				if (x[i].first==z[k].first || z[k].first==y[j].first) continue;
				MIN=min(MIN,m1+m2+m3);
			}
		}
	}
	printf("%d\n",MIN);
	return 0;
}