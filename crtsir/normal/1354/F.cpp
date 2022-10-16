#include<bits/stdc++.h>
using namespace std;
int T,n,k,I[83],dp[83][83],a[83],b[83],pth[83][83];
bool cmp(int x,int y){
	return b[x]<b[y];
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i],I[i]=i;
		sort(I+1,I+n+1,cmp);
		pair<int,vector<int> >ans;ans.first=0;
		while(k>0){
			memset(dp,192,sizeof(dp));
			dp[0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<i;j++)
					dp[i][j]=dp[i-1][j]+(k-1)*b[I[i]],pth[i][j]=j;
				for(int j=0;j<i;j++)
					if(dp[i][j+1]<dp[i-1][j]+a[I[i]]+j*b[I[i]])
						dp[i][j+1]=dp[i-1][j]+a[I[i]]+j*b[I[i]],pth[i][j+1]=j;
			}
			vector<int>v;
			int i=n,j=k;
			while(i){
				if(j!=pth[i][j])
					v.push_back(I[i]);
				j=pth[i][j];i--;
			}
			reverse(v.begin(),v.end());
			ans=max(ans,{dp[n][k--],v});
		}
		vector<int>v=ans.second;
		cout<<2*n-v.size()<<'\n';
		for(int i=0;i<v.size()-1;i++)
			cout<<v[i]<<' ';
		v.push_back(-1); 
		for(int i=1,j=0;i<=n;i++)
			if(v[j]==I[i])
				j++;
			else
				cout<<I[i]<<' '<<-I[i]<<' ';
		cout<<v[v.size()-2]<<'\n';
	}
}