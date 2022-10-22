#include<bits/stdc++.h>
using namespace std;
const int B=320,N=1e5;
int n,ans=1,a[100005],id[100005];
int f[330][200005];
vector<int>v[330];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=-B;i<=B;i++){
		vector<int>w;
		for(int j=1;j<=n;j++)w.push_back(a[j]-i*j);
		sort(w.begin(),w.end());
		for(int j=0,k;j<n;j=k){
			for(k=j;k<n&&w[j]==w[k];k++);
			ans=max(k-j,ans);
		}
	}
	for(int i=0;i<330;i++)for(int j=0;j<200005;j++)
		f[i][j]=1;
	for(int i=1;i<=n;i++){
		id[i]=(id[i-1]+1)%(B+5);
		for(auto x:v[id[i]])f[id[i]][x]=1;
		v[id[i]].clear();
		for(int j=max(1,i-B);j<i;j++){
			int t=a[i]-a[j];
			if(t%(i-j)!=0)continue;
			t/=(i-j),t+=N;
			int tmp=f[id[j]][t]+1;
			v[id[i]].push_back(t);
			ans=max(ans,tmp);
			f[id[i]][t]=max(f[id[i]][t],tmp);
		}
	}
	printf("%d",n-ans);
}