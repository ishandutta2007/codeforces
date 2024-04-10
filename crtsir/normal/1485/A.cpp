#include<bits/stdc++.h>
using namespace std;
int T,tmp,cnt;
int main(){
	cin>>T;
	while(T--){
		int a,b,ans=2147483647;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=114514;i++){
			if(b+i==1)continue;
			tmp=a,cnt=0;
			while(tmp){
				tmp/=(b+i);
				cnt++;
			}
			ans=min(ans,cnt+i);
		}
		cout<<ans<<endl;
	}
}