#include<cstdio>
int n,b[2],b1[2];char x[100001],y[100001];
long long ans;
int main() {
	scanf("%d",&n);
	scanf("%s%s",x,y);
	for(int i=0;x[i];i++){
	  x[i]-=48,y[i]-=48;
	  if(y[i])ans+=b1[x[i]^1];
	  else ans+=b[x[i]^1];
	  b[x[i]]++;
	  if(!y[i])b1[x[i]]++;
	}printf("%I64d",ans);
    return 0;
}