#include<bits/stdc++.h>
using namespace std;

int a[10000],n,x,t,s;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x),s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		if(s==x)printf("NO\n");
		else{
			s=0;
			for(int i=1;i<=n;i++){
				s+=a[i];
				if(s==x){
					swap(a[i],a[i+1]);
					break;
				}
			}
			printf("YES\n");
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			putchar('\n');
		}
	}
}