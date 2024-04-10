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
string ans;
string s[Maxn];
vector<int> loc[Maxn];
char c[Maxn];
pii tree[Maxn*4];
void Push(int p){
	if (tree[p]==mp(0,0)) return;
	tree[p*2+1]=tree[p*2]=tree[p];
	tree[p]=mp(0,0);
}
void modify(int p,int l,int r,int lo,int hi,pii val){
	if (lo<=l && r<=hi){
		tree[p]=val;
		return;
	}
	Push(p);
	int mid=(l+r)>>1;
	if (lo<=mid){
		modify(p*2,l,mid,lo,min(hi,mid),val);
	}
	if (hi>mid){
		modify(p*2+1,mid+1,r,max(lo,mid+1),hi,val);
	}
}
pii query(int p,int l,int r,int x){
	if (l==r){
		return tree[p];
	}
	Push(p);
	int mid=(l+r)>>1;
	if (x<=mid){
		return query(p*2,l,mid,x);
	}
	else{
		return query(p*2+1,mid+1,r,x);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int Max=0;
	for (int i=0;i<n;i++){
		scanf("%s",c);
		s[i]=(string)c;
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			loc[i].pb(x);
			modify(1,1,Maxn,x,(int)x+s[i].length()-1,mp(i,x));
			Max=max(Max,(int)x+(int)s[i].length()-1);
		}
	}
	for (int i=1;i<=Max;i++){
		pair<int,int> x=query(1,1,Maxn,i);
		if (x==mp(0,0)){
			printf("a");
		}
		else{
			printf("%c",s[x.first][i-x.second]);
		}
	}
	printf("\n");
	return 0;
}