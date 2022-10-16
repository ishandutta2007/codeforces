#include<bits/stdc++.h>
using namespace std;
int T,t,x,y;
long long ans[503][503],seq[500003];
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			seq[x]+=y;
			for(int i=1;i<=500;i++)
				ans[i][x%i]+=y;
		}else
			if(x<=500)
				printf("%lld\n",ans[x][y]);
			else{
				long long res=0;
				for(int i=y;i<=500000;i+=x)
					res+=seq[i];
				printf("%lld\n",res);
			}
	}
}