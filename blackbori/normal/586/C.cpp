#include <bits/stdc++.h>

using namespace std;

vector <int> ans;
int n,i,j,k,in,out;
int V[4040],D[4040],P[4040];

int Run(int c)
{
	int l;

	for(l=c+1;l<n;l++) if(P[l]>=0) P[l]-=D[c];
	for(l=c+1;l<n;l++) if(P[l]<0&&P[l]!=-1e9) Run(l),P[l]=-1e9;
	
	return 0;
}

int main()
{
	scanf("%d",&n);
	
	for(i=0;i<n;i++) scanf("%d%d%d",V+i,D+i,P+i);
	
	for(i=0;i<n;i++){
		if(P[i]>=0){
			ans.push_back(i+1);
			for(j=i+1;j<n&&V[i]>0;j++){
				if(P[j]>=0){
					P[j] -= V[i];
					V[i]--;
				}
			}
			for(j=i+1;j<n;j++) if(P[j]<0&&P[j]!=-1e9) Run(j),P[j]=-1e9;
		}
	}
	
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
	
	return 0;
}