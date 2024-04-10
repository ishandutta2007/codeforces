#include<bits/stdc++.h>
using namespace std;
int n,f[110][110][2];
pair<int,int> pr[110];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&pr[i].first,&pr[i].second);
	sort(pr+1,pr+n+1);
	pr[0].first=-1e8;
	int Ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			Ans=max(Ans,max(f[i][j][0],f[i][j][1]));
			int r0=pr[j].first;
			int maxn=-1e9,p,q;
			for(int k=i+1;k<=n;k++){
				int r1=pr[k].first;
				if(r1>maxn) maxn=r1,p=k,q=0;
				f[k][p][q]=max(f[k][p][q],f[i][j][0]+maxn-r1+min(pr[k].second,r1-r0));
				r1=pr[k].first+pr[k].second;
				if(r1>maxn) maxn=r1,p=k,q=1;
				f[k][p][q]=max(f[k][p][q],f[i][j][0]+maxn-r1+min(pr[k].second,r1-r0));
			}
			r0=pr[j].first+pr[j].second;
			maxn=-1e9;
			for(int k=i+1;k<=n;k++){
				int r1=pr[k].first;
				if(r1>maxn) maxn=r1,p=k,q=0;
				f[k][p][q]=max(f[k][p][q],f[i][j][1]+maxn-r1+min(pr[k].second,r1-r0));
				r1=pr[k].first+pr[k].second;
				if(r1>maxn) maxn=r1,p=k,q=1;
				f[k][p][q]=max(f[k][p][q],f[i][j][1]+maxn-r1+min(pr[k].second,r1-r0));
			}
		}
	}
	printf("%d",Ans);
}