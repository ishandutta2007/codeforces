#include<bits/stdc++.h>
using namespace std;
int T,n;
string ans;
int num[5]={1,3,6,45,190},cnt[5];
int main(){
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof(cnt)); 
		ans="";
		scanf("%d",&n);
		int now=2;
		for (;now*(now-1)/2<=n;now++);
		now--;
		n-=now*(now-1)/2;
		for(int i=4;i>=0;i--){
			cnt[i]=n/num[i];
			n%=num[i];
		}
		printf("1");
		for (int i=1;i<=now;i++){
			printf("3");
			for (int j=0;j<5;j++)if(num[j]==i*(i-1)/2)
				for (int k=0;k<cnt[j];k++) printf("7");
		}
		printf("7\n");
	}
}