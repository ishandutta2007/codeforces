#include<bits/stdc++.h>
using namespace std;
int t,n,m;vector<int>a;
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		a=vector<int>(n+1,0);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int tmp=n;
		for(;tmp>=1&&a[tmp]==tmp;tmp--);
		double ans=1; 
		for(int i=1;i<=m;i++){
			int r;double x;
			cin>>r>>x;
			if(r>=tmp)ans*=1-x;
		}
		if(tmp==0){
			ans=0;;
		}
		printf("%.10lf\n",1-ans);
		
	}
	return 0;
}