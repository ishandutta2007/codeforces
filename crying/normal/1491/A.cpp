#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int MAXN=1e5+10;
int n,q,a[MAXN],cnt1,cnt2;
int opt,x;
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i])cnt1++;
		else cnt2++;
	}
	rep(i,1,q){
		scanf("%d%d",&opt,&x);
		if(opt==1){
			if(a[x]==1)a[x]=0,cnt1--,cnt2++;
			else a[x]=1,cnt1++,cnt2--;
		}else{
			if(x<=cnt1)printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}