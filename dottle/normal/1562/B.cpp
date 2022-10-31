#include<bits/stdc++.h>
using namespace std;

int t,k,a[100],v[100],p[100];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		memset(v,0,sizeof(v));
		memset(p,0,sizeof(p));
		for(int i=1;i<=k;i++)scanf("%1d",&a[i]); 
		int fl=0;
		for(int i=k;i;i--)
			if((a[i]%2==0&&a[i]!=2)||(a[i]%3==0&&a[i]!=3)||a[i]==1){
				printf("1\n%d\n",a[i]),fl=1;
				break;
			}
		if(fl)continue;
		for(int i=k;i;i--){
			if(v[a[i]]){printf("2\n%d%d\n",a[i],a[i]),fl=1;break;}v[a[i]]=1;
			if(p[3-a[i]%3]){printf("2\n%d%d\n",a[i],p[3-a[i]%3]),fl=1;break;}p[a[i]%3]=a[i];
			if(a[i]==5&&i>1){printf("2\n%d%d\n",a[i-1],5),fl=1;break;}
			if(a[i]==2&&i>1){printf("2\n%d%d\n",a[i-1],2),fl=1;break;}
		}
	}
}