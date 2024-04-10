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
const int Maxn=100005;
multiset<int> now;
vector<pair<int,int> > x; 
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int h,l,r;
		scanf("%d %d %d",&h,&l,&r);
		x.push_back(mp(l,h));
		x.push_back(mp(r,~h)); 
	}
	sort(x.begin(),x.end());
	vector<pair<int,int> > ans;
	ans.push_back(mp(-2e9,0));
	now.insert(0);
	for (int i=0;i<x.size();){
		int pos=x[i].first;
		while (x[i].first==pos){
			if (x[i].second>0){
				now.insert(x[i].second);
			}
			else{
				now.erase(now.find(~x[i].second));
			}
			i++;
		}
		int preh=ans.back().second;
		int nowh;
		multiset<int>::iterator it;
		it=now.end();
		it--;
		nowh=*it;
		if (preh!=nowh){
			ans.push_back(mp(pos,preh));
			ans.push_back(mp(pos,nowh)); 
		}
	}
	printf("%d\n",ans.size()-1);
	for (int i=1;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}