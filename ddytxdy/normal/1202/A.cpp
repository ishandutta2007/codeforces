#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int t,low,la,lb,ans;char a[N],b[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",a+1,b+1);
		la=strlen(a+1);lb=strlen(b+1);
		reverse(a+1,a+la+1);
		reverse(b+1,b+lb+1);
		for(int i=1;i<=lb;i++)if(b[i]=='1'){low=i;break;}
		for(int i=1;i<=la;i++)if(a[i]=='1'&&low<=i){ans=i-low;break;}
		printf("%d\n",ans);
	}
}