#include<bits/stdc++.h>
using namespace std;
int T,n;
double ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		vector<double>v1,v2;
		ans=0.0;
		for(int i=0;i<2*n;i++){
			int x,y;scanf("%d%d",&x,&y);
			if(x==0)v1.push_back(fabs(y));
			else v2.push_back(fabs(x));
		}
		sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end());
		for(int i=0;i<n;i++)ans+=sqrt(v1[i]*v1[i]+v2[i]*v2[i]);
		printf("%.9lf\n",ans);
	}
}