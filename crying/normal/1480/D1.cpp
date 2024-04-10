#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN],next[MAXN],t[MAXN];
int x,y,ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
	}
	per(i,n,1){
		if(t[a[i]])next[i]=t[a[i]];
		else next[i]=n+1;
		t[a[i]]=i;
	}
	next[0]=n+1;
	rep(i,1,n){
		if(a[i]!=a[x] && a[i]!=a[y]){
			ans++;
			if(next[x]<next[y]){
				x=i;
			}else{
				y=i;
			}
		}else{
			if(a[i]!=a[x] || a[i]!=a[y])ans++;
			x=y=i;
		}
	}
	printf("%d",ans);
	return 0;
}