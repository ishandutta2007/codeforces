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
const int Maxn=200005;
char tp[Maxn][10];
int x[Maxn],y[Maxn];
map<int,int> to;
int from[Maxn];
set<int> now[Maxn];
int tree[Maxn*4];
int cnt=0;
pair<int,int> Get(int p,int l,int r,int lo,int val){
	if (lo>r) return mp(-1,-1);
	if (tree[p]<=val) return mp(-1,-1);
	if (l==r){
		return mp(l,*now[l].lower_bound(val+1));
	}
	int mid=(l+r)>>1;
	if (lo<=mid){
		pii tmp=Get(p*2,l,mid,lo,val);
		if (tmp!=mp(-1,-1)) return tmp;
	}
	return Get(p*2+1,mid+1,r,lo,val);
}
void modify(int p,int l,int r,int pos,int val){
	if (l==r){
		tree[p]=val;
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid){
		modify(p*2,l,mid,pos,val);
	}
	else{
		modify(p*2+1,mid+1,r,pos,val);
	}
	tree[p]=max(tree[p*2],tree[p*2+1]);
}
void Update(int pos){
	// pos is in [1,Maxn]
	if (now[pos].empty()) modify(1,1,cnt,pos,-1);
	else modify(1,1,cnt,pos,*now[pos].rbegin());
}
void _init(){
	memset(tree,-1,sizeof(tree));
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s %d %d",tp[i],&x[i],&y[i]);
		to[x[i]]=0;
	}

	for (map<int,int>::iterator it=to.begin();it!=to.end();it++){
		it->second=++cnt;
		from[it->second]=it->first;
	}
	for (int i=1;i<=n;i++){
		if (tp[i][0]=='a'){
			int X=to[x[i]],Y=y[i];
			now[X].insert(Y);
			Update(X);
		}
		else if (tp[i][0]=='r'){
			int X=to[x[i]],Y=y[i];
			now[X].erase(Y);
			Update(X);
		}
		else{
			int X=to[x[i]],Y=y[i];
			pii res=Get(1,1,cnt,X+1,Y);
			if (res.first==-1) printf("-1\n");
			else printf("%d %d\n",from[res.first],res.second);
		}//ff
	}
	return 0;
}