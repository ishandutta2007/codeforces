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
const int Maxn=1e6+5;
char s[Maxn],t[Maxn];
int os[27],ot[27];
int res[27];
int main(){
	scanf("%s\n",s);
	scanf("%s",t);
	int cnt=0;
	int n=strlen(s);
	int m=strlen(t);
	for (int i=0;i<n;i++){
		if (s[i]!='?') os[s[i]-'a']++;
		else cnt++;
	}
	for (int i=0;i<m;i++){
		if (t[i]!='?') ot[t[i]-'a']++;
	}
	int ans=0;
	for (;;){
		bool flag=true;
		for (int i=0;i<26;i++){
			if (os[i]>=ot[i]) os[i]-=ot[i];
			else{
				int re=ot[i]-os[i];
				os[i]=0;
				if (cnt>=re){
					cnt-=re;
					res[i]+=re;
				}
				else{
					flag=false;
					break;
				}
			}
		}
		if (!flag) break;
	}
	int j=0;
	for (int i=0;i<n;i++){
		while (j<26 && res[j]<=0){
			j++;
		}
		if (j>=26) j=25;
		if (s[i]=='?') s[i]=j+'a',res[j]--;
	}
	printf("%s\n",s);
	return 0;
}