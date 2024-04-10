#include<bits/stdc++.h>
using namespace std;
int n,m,g[613][103];
bool x;
int main(){
	cin>>n>>m;
	if(n>m)x=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];
	vector<bool>v;
	vector<int>v2;/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<g[i][j]<<' ';
		cout<<endl;
	}*/
	if(x==0){
		for(int i=0;i<n;){
			int can=1;
			for(int j=0;j<m;j++)
				can&=(g[i][j]>0);
			if(can)
			{
				for(int j=0;j<m;j++)
					g[i][j]--;
				v.push_back(x);
				v2.push_back(i+1);
			}
			else
				i++;
		}
		for(int i=0;i<m;){
			int can=1;
			for(int j=0;j<n;j++)
				can&=(g[j][i]>0);
			if(can)
			{
				for(int j=0;j<n;j++)
					g[j][i]--;
				v.push_back(x^1);
				v2.push_back(i+1);
			}
			else
				i++;
		}
	}else{
			for(int i=0;i<m;){
			int can=1;
			for(int j=0;j<n;j++)
				can&=(g[j][i]>0);
			if(can)
			{
				for(int j=0;j<n;j++)
					g[j][i]--;
				v.push_back(x);
				v2.push_back(i+1);
			}
			else
				i++;
		}
		for(int i=0;i<n;){
			int can=1;
			for(int j=0;j<m;j++)
				can&=(g[i][j]>0);
			if(can)
			{
				for(int j=0;j<m;j++)
					g[i][j]--;
				v.push_back(x^1);
				v2.push_back(i+1);
			}
			else
				i++;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j])
			{
				cout<<-1;
				return 0;
			}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		if(!v[i])cout<<"row ";
		else cout<<"col ";
		cout<<v2[i]<<endl;
	}
}