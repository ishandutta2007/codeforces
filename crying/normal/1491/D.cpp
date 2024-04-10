#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
int q,u,v,sum1[40],sum2[40];
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v);
		memset(sum1,0,sizeof sum1);
		memset(sum2,0,sizeof sum2);
		if(u>v){
			printf("NO\n");continue;
		}
		rep(j,1,30){
			sum1[j]=sum1[j-1];sum2[j]=sum2[j-1];
			if(u&1)sum1[j]++;
			if(v&1)sum2[j]++;
			u/=2;v/=2;
		}
		rep(j,1,30){
			if(sum1[j]<sum2[j])goto END;
		}
		printf("YES\n");continue;
		END:printf("NO\n");
	}
	return 0;
}