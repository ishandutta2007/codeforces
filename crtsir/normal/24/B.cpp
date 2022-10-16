#include<bits/stdc++.h>
using namespace std;
map<string,vector<int> >mp;
map<string,int>num;
map<int,string>mun;
int n,t,cnt,pnt[53]={25,18,15,12,10,8,6,4,2,1,0,0,0,0,0,0,0,0};
vector<int>v[53];
string dr[53],s;
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>s;
			if(!num[s])
				num[s]=++cnt,
				mun[cnt-1]=s;
			v[num[s]-1].push_back(j);	
		}
	}
	for(int i=0;i<cnt;i++)
		num[mun[i]]=i;
	for(int i=0;i<cnt;i++)
		for(int j=0;j<53;j++)
			mp[mun[i]].push_back(0);
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<v[i].size();j++)
			mp[mun[i]][0]+=pnt[v[i][j]],
			//cout<<"HELLO",
			mp[mun[i]][v[i][j]+1]++;
	}
	vector<int>best=mp[mun[0]];
	int nbr=0;
	swap(mp[mun[0]][0],mp[mun[0]][1]);
	for(int i=1;i<cnt;i++)
	{
		if(best<mp[mun[i]])
			best=mp[mun[i]],
			nbr=i;
		swap(mp[mun[i]][0],mp[mun[i]][1]);
	}
	cout<<mun[nbr]<<endl;
	best=mp[mun[0]];
	nbr=0;
	for(int i=1;i<cnt;i++)
	{
		if(best<mp[mun[i]])
			best=mp[mun[i]],
			nbr=i;
	}
	cout<<mun[nbr];
}