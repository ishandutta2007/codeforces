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
// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=35005;
const int Maxk=55;
int tree[Maxk][4*Maxn],tag[Maxk][4*Maxn];
int dp[Maxk][Maxn];
int n,k;
void Push(int t,int p){
	tag[t][p*2]+=tag[t][p];
	tag[t][p*2+1]+=tag[t][p];
	tag[t][p]=0;
}
void modify(int t,int p,int l,int r,int pos,int val){
	if (l==r){
		tree[t][p]=val;
		return;
	}
	Push(t,p);
	int mid=(l+r)>>1;
	if (pos<=mid){
		modify(t,p*2,l,mid,pos,val);
	}
	else{
		modify(t,p*2+1,mid+1,r,pos,val); 
	}
	tree[t][p]=max(tree[t][p*2]+tag[t][p*2],tree[t][p*2+1]+tag[t][p*2+1]);
}
void Add(int t,int p,int l,int r,int lo,int hi,int val){
	if (lo>hi || !hi) return;
	if (!lo) lo++;
	if (lo<=l && r<=hi){
		tag[t][p]+=val;
		return;
	}
	Push(t,p);
	int mid=(l+r)>>1;
	if (lo<=mid){
		Add(t,p*2,l,mid,lo,min(hi,mid),val); 
	}
	if (hi>mid){
		Add(t,p*2+1,mid+1,r,max(lo,mid+1),hi,val);
	}
	tree[t][p]=max(tree[t][p*2]+tag[t][p*2],tree[t][p*2+1]+tag[t][p*2+1]);
}
int query(int t,int p,int l,int r,int lo,int hi){
	if (lo>hi) return -1e9;
	if (lo<=l && r<=hi){
		return tree[t][p]+tag[t][p];
	}
	Push(t,p);
	int mid=(l+r)>>1;
	int ans=0;
	if (lo<=mid){
		ans=max(ans,query(t,p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=max(ans,query(t,p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	return ans;
}
int a[Maxn];
int pre[Maxn];
int hav[Maxn];
int main(){
	memset(hav,-1,sizeof(hav));
	scanf("%d %d",&n,&k);
	int sum=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (hav[a[i]]!=-1) pre[i]=hav[a[i]];
		else sum++;
		hav[a[i]]=i;
		dp[1][i]=sum;
		modify(1,1,1,n,i,sum);
		//cout<<dp[1][i]<<' ';
	}
	//cout<<endl;
	for (int i=2;i<=k;i++){
		for (int j=1;j<=n;j++){
			// dp[i][j] 
		//	cout<<pre[j]+1<<j<<endl;
			Add(i-1,1,1,n,pre[j],j-1,1);
		//	cerr<<123;
			dp[i][j]=query(i-1,1,1,n,1,j-1);
			
		//	cerr<<123;
			modify(i,1,1,n,j,dp[i][j]);
			//cout<<dp[i][j]<<' ';
		}
	//	cout<<endl;
	}
	printf("%d\n",dp[k][n]);
	return 0;
}
/*
4 1
1 2 2 1
*/