#include<cstdio>
#define D for(i=2;i<=n;i+=2)printf("1 %d %d\n",i,i+1);
int n,i,a,s;
int main(){scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",&a),s^=a;if((n&1)^1){--n;if(s!=0)return puts("NO"),0;}printf("YES\n%d\n",n-1);D D}