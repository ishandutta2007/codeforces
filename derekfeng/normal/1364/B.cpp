#include<bits/stdc++.h>
using namespace std;
int n,T,x,lst,p[100004];
vector<int>res;
int main(){
	cin>>T;
	while(T--){
		int L=1;
		scanf("%d",&n);
		scanf("%d%d",&p[1],&p[2]);L=1,lst=p[2];
		res.clear();
		for(int i=3;i<=n;i++){
			scanf("%d",&p[i]);
			if(1ll*(lst-p[i])*(p[L]-lst)<0)res.push_back(p[L]),L=i-1;
			lst=p[i];
		}
		res.push_back(p[L]);
		res.push_back(p[n]);
		printf("%d\n",(int)res.size());
		for(int i=0;i<res.size();i++)printf("%d ",res[i]);puts("");
	}
}