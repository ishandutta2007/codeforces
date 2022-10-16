#include<bits/stdc++.h>
using namespace std;
vector<int>v[400003];
int dis[400003];
int main(){
	int n,d,k,cnt;
	cin>>n>>d>>k;
	if(d>=n||(k==1&&n>2)){
		cout<<"NO";
		return 0;
	}
	for(int i=0;i<d;i++)
		v[i].push_back(i+1),cnt++,
		v[i+1].push_back(i);
	for(int i=0;i<=d;i++)
		dis[i]=max(i,d-i);
	int j=1;
	for(int i=d+1;i<n;i++)
		for(j;j<i;j++)
			if(v[j].size()<k&&dis[j]<d)
			{
				v[j].push_back(i);
				v[i].push_back(j);
				dis[i]=dis[j]+1;
				cnt++;
				break;
			}
	if(cnt<n-1){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
		if(v[i].size())
			for(j=0;j<v[i].size();j++)
				if(i<v[i][j])
					cout<<i+1<<' '<<v[i][j]+1<<endl;
}