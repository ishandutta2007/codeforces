#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=300005;
int a[N],n,m;

int chk(int x){
	int las=0;
	rep(i,1,n){
		//printf("# %d %d %d\n",x,i,las);
		if(a[i]+x<las)return 0;
		if(a[i]<=las||a[i]+x>=m&&(a[i]+x)%m>=las)continue;
		las=max(las,a[i]);
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	int l=0,r=m-1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(chk(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}