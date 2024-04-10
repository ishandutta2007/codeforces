#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[53][53],b[52][52];
	vector<pair<int,int> >ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m-1;j++)
			if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1])
			{
				ans.push_back(make_pair(i+1,j+1));
				b[i][j]=1;
				b[i][j+1]=1;
				b[i+1][j]=1;
				b[i+1][j+1]=1;
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]!=b[i][j]){
				cout<<-1;
				return 0;
			}
	cout<<ans.size();
	for(int i=0;i<ans.size();i++)
		cout<<endl<<ans[i].first<<' '<<ans[i].second;
}