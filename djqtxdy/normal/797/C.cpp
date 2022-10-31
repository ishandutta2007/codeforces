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
vector<char> v;
const int Maxn=100005;
pair<char,int> Min[Maxn];
int main(){
	string s;
	cin>>s;
	Min[s.length()-1]=mp(s[s.length()-1],s.length()-1);
	for (int i=s.length()-2;i>=0;i--){
		Min[i]=Min[i+1];
		if (s[i]<=Min[i].first){
			Min[i]=mp(s[i],i);
		}
	}
	int now=0;
	while (1){
		char c1;
		if (now!=s.length()) c1=Min[now].first; else c1='z'+1;
		char c2;
		if (v.empty()) c2='z'+1; else c2=v.back();
		int now2=Min[now].second;
		if (c1=='z'+1 && c2=='z'+1) break;
		if (c2>c1){
			for (int i=now;i<now2;i++){
				v.push_back(s[i]);
			}
			cout<<s[now2];
			now=now2+1;
		}
		else{
			cout<<v.back();
			v.pop_back();
		}
	}
	return 0;
}