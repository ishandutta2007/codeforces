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
const int Maxn=2e6+5;
vector<int> pos[Maxn];
vector<int> pp[Maxn];
string s[Maxn];
char c[Maxn];
int cnt[Maxn];
char ans[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	int Max=0;
	for (int i=1;i<=n;i++){
		scanf("%s",c);
		s[i]=(string)c;
		int l=strlen(c);
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			pp[i].push_back(x);
			int e=x+l-1;
			pos[x].push_back(i);
			pos[e+1].push_back(-i);
			Max=max(Max,e);
		}
	}
	vector<int> now;
	for (int i=1;i<=Max;i++){
		for (int j=0;j<pos[i].size();j++){
			if (pos[i][j]<0){
				cnt[-pos[i][j]]--;
			}
			else{
				if (cnt[pos[i][j]]==0){
					now.push_back(pos[i][j]);
				}
				cnt[pos[i][j]]++;
			}
		}
		while (1){
			if (now.empty() || cnt[now.back()]!=0) break;
			now.pop_back();
		}
		if (now.empty()) ans[i]='a';
		else{
			int col=now.back();
			int st=upper_bound(pp[col].begin(),pp[col].end(),i)-pp[col].begin();
			st--;
			st=pp[col][st];
			ans[i]=s[col][i-st];
		}
		printf("%c",ans[i]);
	}
	printf("\n");
	return 0;
}