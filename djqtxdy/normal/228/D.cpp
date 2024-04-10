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
const int Maxt=300005;
long long t[7][12][Maxt];
int a[Maxn];
void modify(int t1,int t2,int l,int r,int p,int k,long long val){
//	cout<<l<<r<<endl;
	if (l==r){
		t[t1][t2][p]=val;
		return;
	}
	int m=(l+r)/2;
	if (k<=m){
		modify(t1,t2,l,m,p*2,k,val);
	}
	else{
		modify(t1,t2,m+1,r,p*2+1,k,val);
	}
	t[t1][t2][p]=t[t1][t2][p*2]+t[t1][t2][p*2+1];
}
long long query(int t1,int t2,int l,int r,int p,int lo,int hi){
	if (l>=lo && r<=hi) return t[t1][t2][p];
	int m=(l+r)/2;
	long long ans=0;
	if (lo<=m){
		ans+=query(t1,t2,l,m,p*2,lo,min(m,hi));
	}
	if (hi>m){
		ans+=query(t1,t2,m+1,r,p*2+1,max(lo,m+1),hi);
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for (int j=2;j<=6;j++){
			modify(j,i%(2*j-2),1,n,1,i,(LL)a[i]);
		}
	}
	int m;
	scanf("%d",&m);
	while (m--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int p,val;
			scanf("%d %d",&p,&val);
			for (int j=2;j<=6;j++){
				modify(j,p%(2*j-2),1,n,1,p,(LL)val);
			}
		}
		else{
			int lf,rg,z;
			scanf("%d %d %d",&lf,&rg,&z);
			long long ans=0;
			z=2*z-2;
			int now=lf%z;
			for (int i=1;i<=z;i++){
				int si;
				if (i==0) si=2;
				else if (i<=(z+2)/2){
					si=i;
				}
				else{
					si=z+2-i;
				}
				ans+=(LL)si*query((z+2)/2,(now+i-1)%z,1,n,1,lf,rg);
			}
			printf("%I64d\n",ans);
		}
	}
}
//gym 100962 F
//spoj cot2
/*
5
2 3 5 5 5
4
2 2 3 2
2 1 5 3
1 3 1
2 1 5 3
*/