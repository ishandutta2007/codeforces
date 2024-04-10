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
#include <assert.h>
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
const int Maxn=105;
int l[Maxn],r[Maxn];
int p[Maxn];
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	p[x]=y;
	return;
}
void _init(){
	for (int i=0;i<Maxn;i++) p[i]=i;
}
set<int> lz,rz;
int main(){
	_init(); 
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d %d",&l[i],&r[i]);
		if (!l[i]){
			lz.insert(i);
		}
		else{
			Union(i,l[i]);
		}
		if (!r[i]){
			rz.insert(i);
			
		}else Union(i,r[i]); 
	}
//	for (int i=1;i<=n;i++) cout<<p[i]<<endl;
	//return 0;
	while (lz.size()!=1 || rz.size()!=1){//cout<<lz.size()<<' '<<rz.size()<<endl;
		int xxx=*lz.begin(),xxxx=-1;
		for (auto xx:rz){
			//cout<<findset(xxx)<<' '<<findset(xx)<<endl;
			if (findset(xxx)!=findset(xx)){
				l[xxx]=xx;
				r[xx]=xxx;
				xxxx=xx;
				//cout<<xx<<endl;
				Union(xxxx,xxx);
				break;
			}
		}
		//cout<<xxxx<<endl;
		lz.erase(xxx);
		rz.erase(xxxx);
	}
	for (int i=1;i<=n;i++){
		printf("%d %d\n",l[i],r[i]);
	}
	return 0;
}