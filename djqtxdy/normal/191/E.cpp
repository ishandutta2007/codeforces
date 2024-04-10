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
long long a[Maxn],s[Maxn],ts[Maxn];
long long BIT[Maxn],to[Maxn];
map<long long,int> f;
int cnt=0;
void _init(){
	for (int i=0;i<Maxn;i++){
		BIT[i]=0LL;
	}
}
void add(int pos,long long val){
	while (pos<=cnt){
		BIT[pos]+=val;
		pos+=pos&-pos;
	}
}
long long query(int pos){
	long long res=0;
	while (pos>0){
		res+=BIT[pos];
		pos-=pos&-pos;
	}
	return res;
}
int main(){
	int n;
	long long k;
	scanf("%d %I64d",&n,&k);
//	k=(LL)n*(n+1)/2-k+1;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		s[i]=s[i-1]+a[i];
	//	ts[i]=s[i];
		f[s[i]]=0;
	}

	for (map<long long,int>::iterator it=f.begin();it!=f.end();it++){
		it->second=++cnt;
		to[cnt]=it->first;
		
	}
	for (int i=1;i<=n;i++) s[i]=f[s[i]];
	long long l=-1e15,r=1e15;
	while (r-l>1){
		long long ans=0;
		_init();
		long long mid=(l+r)/2;
		for (int i=1;i<=n;i++){
			add(s[i],1);
		}
		//>=mid
		//>=mid+s[i-1];
		for (int i=1;i<=n;i++){
			long long val=mid+to[s[i-1]];
			int loc=lower_bound(to+1,to+cnt+1,val)-to;
			//if (loc==cnt+1) continue;
			//cout<<val<<' '<<loc<<' '<<(query(cnt)-query(loc-1))<<endl;
			ans+=(query(cnt)-query(loc-1));
			add(s[i],-1);
		}
		if (ans<k){
			r=mid;
		}
		else{
			l=mid;
		}
	//	cout<<"midans:"<<mid<<' '<<ans<<endl;
	//	cout<<"lr"<<l<<' '<<r<<endl;
	}
	printf("%I64d\n",l);
	return 0;
}