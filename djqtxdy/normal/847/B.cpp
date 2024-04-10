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
int tree[Maxn*4];
int a[Maxn];
void build(int p,int l,int r){
	if (l==r){
		tree[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tree[p]=max(tree[p*2],tree[p*2+1]);
}
void modify(int p,int l,int r,int pos,int val){
	if (l==r){
		tree[p]=val;
		//out<<tree[p]<<endl;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid){
		modify(p*2,l,mid,pos,val);
	}
	else{
		modify(p*2+1,mid+1,r,pos,val);
	}
	tree[p]=max(tree[p*2],tree[p*2+1]);
	
}
int query(int p,int l,int r,int val){
	if (tree[p]<=val){
		return -1;
	}
	if (l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if (tree[p*2]<=val){
		return query(p*2+1,mid+1,r,val);
	}
	else{
		return query(p*2,l,mid,val);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	//cout<<query(1,1,n,1)<<endl;
	//return 0;
	int pos=1;
	while (1){
		while (1){
			if (a[pos]!=-1) break;
			pos++;
		}
		if (pos==n+1) break;
		int poss=pos;
		while (1){
			printf("%d ",a[poss]);
			
			int tmp=poss;
			poss=query(1,1,n,a[poss]);
			//cerr<<a[poss]<<endl;
			a[tmp]=-1;
			modify(1,1,n,tmp,-1);
			if (poss==-1) break;
		}
	//	cout<<a[pos]<<endl;
		printf("\n");
	}
}