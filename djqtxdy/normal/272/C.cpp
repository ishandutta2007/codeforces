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
const int Maxn=100005;
const int Maxt=900009;
long long Tree[Maxt],tag[Maxt];
int a[Maxn];
void build_tree(int l,int r,int p){
	if (l==r){
	//	if (l==5)cout<<p;
		Tree[p]=(LL)a[l];
		tag[p]=-1;
		return;
	}
	int mid=(l+r)/2;
	build_tree(l,mid,p*2);
	build_tree(mid+1,r,p*2+1);
	tag[p]=-1;
	Tree[p]=max(Tree[p*2],Tree[p*2+1]);
}
void pull(int p){
	if (tag[p]==-1) return;
//	cout<<"PULL"<<p<<endl;
	Tree[p]=tag[p];
	tag[p*2]=tag[p*2+1]=tag[p];
	Tree[p*2]=Tree[p*2+1]=tag[p];
	tag[p]=-1;
}
long long query(int l,int r,int p,int lo,int hi){
	if (tag[p]!=-1){
		//cout<<"q:"<<l<<r<<endl;;
		return tag[p];
	}
	//else cout<<"-1:"<<p<<endl;
	if (l>=lo && r<=hi) {
		return Tree[p];
	}
	int mid=(l+r)/2;
	long long ans=0;
	if (lo<=mid){
		ans=max(ans,query(l,mid,p*2,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=max(ans,query(mid+1,r,p*2+1,max(lo,mid+1),hi));
	}
	return ans;
}
void modify(int l,int r,int p,int lo,int hi,long long val){
if (l!=r)pull(p);
	if (l>=lo && r<=hi){
		//cout<<"lr:"<<l<<r<<val<<endl;
		Tree[p]=tag[p]=val;
		return;
	}
	
	int mid=(l+r)/2;
	if (lo<=mid){
		modify(l,mid,p*2,lo,min(hi,mid),val);
	}
	if (hi>mid){
		modify(mid+1,r,p*2+1,max(lo,mid+1),hi,val);
	}
	Tree[p]=max(Tree[p*2],Tree[p*2+1]);
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build_tree(1,n,1);
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		int w,h;
		scanf("%d %d",&w,&h);
		long long hei=query(1,n,1,1,w);
		printf("%I64d\n",hei);
		modify(1,n,1,1,w,hei+(LL)h);
	}
	return 0;
} 
/*
5
4 7 10 12 12
9
3 9
2 1
3 5
4 7
1 1
5 1
1 7
2 4
4 10
*/