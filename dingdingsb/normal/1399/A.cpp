#include<bits/stdc++.h>
using namespace std;
int t ;
signed main(){
	scanf("%d",&t);
	while(t--){
		int n,a;
		scanf("%d",&n);
		int num[100+10];
		memset(num,0,sizeof num);
		for(int i=1;i<=n;i++)
			scanf("%d",&a),num[a]++;
		bool flag=true;
		for(int i=0;i<=100;i++)
			if(num[i]){
                //printf("%d  %d\n",t,i);
				int j=i+1;
				while(num[j])
					j++;
				// 
				for(int w=j;w<=100;w++)
					if(num[w]){
						flag=false;
						break;
					}
				if(!flag)break;
			}
		puts(flag?"YES":"NO");
	}
	return 0;
}