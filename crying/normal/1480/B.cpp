#include<bits/stdc++.h>
#define next Cry_For_theMoon
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
ll T,A,B,n,a[MAXN],b[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>A>>B>>n;
		ll cost=0,maxcost=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll flag=1;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			ll cnt=(b[i]+A-1)/A;
			if(cnt>0)maxcost=max(maxcost,a[i]);
			B-=cnt*a[i];
		}
		if(B+maxcost<=0)printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}