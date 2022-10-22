#include<bits/stdc++.h>
using namespace std;
int t,n;char str[300000+100];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",str+1);
		int n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++)
			if(str[i]=='<')n1++;
			else if(str[i]=='-')n2++;
			else if(str[i]=='>')n3++;
		if(n1==0||n3==0)printf("%d\n",n);
		else{
			vector<bool>can(n,false);
			for(int i=1;i<=n;i++)
				if(str[i]=='-')
					can[i-1]=true,can[i%n]=true;
			int cnt=0;
			for(int i=0;i<n;i++)
				cnt+=can[i];
			printf("%d\n",cnt);
		}
	}
	return 0;
}