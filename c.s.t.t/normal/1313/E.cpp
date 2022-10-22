#include<bits/stdc++.h>
using namespace std;
#define int long long
int S,T,P,Z[2001000],f[500100],g[500100],res,BIT1[1001000],BIT2[1001000];
char s[2001000];
void Zalgo(char *p,char *t){
	memcpy(s,p,P),s[P]='#',memcpy(s+P+1,t,T),S=P+T+1;
	int l=0,r=0;
	for(int i=1;i<S;i++){
		Z[i]=0;
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(i+Z[i]<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(Z[i]+i>r)l=i,r=Z[i]+i;
	}
}
char t1[500100],t2[500100],p[1001000];
void ADD(int *t,int x,int val){
	x=max(x,1ll);
	while(x<=P)t[x]+=val,x+=x&-x;
}
int SUM(int *t,int x){
	int sum=0;
	while(x)sum+=t[x],x-=x&-x;
	return sum;
}
signed main(){
	scanf("%lld%lld",&T,&P),P--;
	scanf("%s%s%s",t1,t2,p);
	Zalgo(p,t1);
	for(int i=P+1;i<S;i++)f[i-P-1]=Z[i];
	reverse(p+1,p+P+1),reverse(t2,t2+T);
	Zalgo(p+1,t2);
	for(int i=P+1;i<S;i++)g[i-P-1]=Z[i];
	P++;
	reverse(g,g+T);
//	for(int i=0;i<T;i++)printf("%d ",f[i]);puts("");
//	for(int i=0;i<T;i++)printf("%d ",g[i]);puts("");
	for(int i=0,j=0;i<T;i++){
		while(j<=min(T-1,i+P-2))ADD(BIT1,P-g[j]-1,1),ADD(BIT2,P-g[j]-1,P-g[j]-1),j++;
		res+=SUM(BIT1,f[i])*f[i]-SUM(BIT2,f[i]);
//		printf("%d\n",res);
		ADD(BIT1,P-g[i]-1,-1),ADD(BIT2,P-g[i]-1,g[i]-P+1);
	}
	printf("%lld\n",res);
	return 0;
}