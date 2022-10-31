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
#define INF 1e9
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
// cf IO: I64d
// atcoder IO: 
const int Maxn=100005;
int b[Maxn];
int num[Maxn];
pii a[Maxn];
int BIT[Maxn];
int tree[Maxn*4];
int n;
void modify(int p,int l,int r,int x,int val){
	if (l==r){
		tree[p]=val;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) modify(p*2,l,mid,x,val);
	else modify(p*2+1,mid+1,r,x,val);
	tree[p]=min(tree[p*2],tree[p*2+1]);
}
int st_query(int p,int l,int r,int lo,int hi){
	if (lo<=l && r<=hi){
		return tree[p];
	}
	int mid=(l+r)>>1;
	int ans=INF;
	if (lo<=mid){
		ans=min(ans,st_query(p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		ans=min(ans,st_query(p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	return ans;
}
void _init(){
	for (int i=0;i<Maxn;i++){
		BIT[i]=0;
	}
}
void add(int pos,int val){
	while (pos<=n){
		BIT[pos]+=val;
		pos+=pos&-pos;
	}
}
int query(int pos){
	int res=0;
	while (pos>0){
		res+=BIT[pos];
		pos-=pos&-pos;
	}
	return res;
}
int main(){
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		b[i]=a[i].first;
		a[i].second=i;
	}
	sort(a+1,1+a+n);
	for (int i=1;i<=n;i++){
		num[a[i].second]=i;
		add(i,1);
		modify(1,1,n,i,b[i]);
	}
	int now=1;
	LL ans=0LL;
	for (int i=1;i<=n;i++){
		int val=a[i].first;
		int pos;
		if (st_query(1,1,n,now,n)==val){
			int lo=now,hi=n;
			while (hi-lo>1){
				int mid=(lo+hi)>>1;
				if (st_query(1,1,n,now,mid)==val){
					hi=mid;
				}
				else{
					lo=mid;
				}
			}
			if (st_query(1,1,n,now,lo)==val) pos=lo;
			else pos=hi;
		}
		else{
			int lo=1,hi=now-1;
			while (hi-lo>1){
				int mid=(lo+hi)>>1;
				if (st_query(1,1,n,1,mid)==val){
					hi=mid;
				}
				else{
					lo=mid;
				}
			}
			if (st_query(1,1,n,1,lo)==val) pos=lo;
			else pos=hi;
		}
	//	cout<<pos<<endl;
		//cout<<pos<<' '<<now<<' '<<ans<<endl;
		if (pos>=now){
			ans+=(LL)query(pos)-query(now-1);
		}
		else{
			ans+=(LL)query(pos);
			ans+=(LL)query(n)-query(now-1);
		}
		add(pos,-1);
		modify(1,1,n,pos,INF);
		now=pos+1;
		if (now==n+1) now==1;
	}
	printf("%I64d\n",ans);
	return 0;
}