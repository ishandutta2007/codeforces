#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[103][103],dx[4]={0,0,1,1},dy[4]={0,1,0,1};
char c[103][103];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>c[i][j],
				a[i][j]=c[i][j]-'0';
		vector<int>v[6];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]==1){
					for(int k=1;k<4;k++){
						int cnt=0;
						v[cnt++].push_back(i);
						v[cnt++].push_back(j);
						for(int l=1;l<4;l++)
							if(k!=l){
								v[cnt++].push_back(i+1<n?i+dx[l]:i-dx[l]);
								v[cnt++].push_back(j+1<m?j+dy[l]:j-dy[l]);
							}
					}
				} 
		cout<<v[0].size()<<'\n';
		for(int i=0;i<v[0].size();i++)
			cout<<v[0][i]+1<<' '<<v[1][i]+1<<' '<<v[2][i]+1<<' '<<v[3][i]+1<<' '<<v[4][i]+1<<' '<<v[5][i]+1<<endl; 
	}
}