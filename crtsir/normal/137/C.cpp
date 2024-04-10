#include<bits/stdc++.h>
using namespace std;
pair<int,int>p[200020];
int main()
{
	int x,n,y,res=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x>>y,
		p[i*2]=make_pair(x,i+1),
		p[i*2+1]=make_pair(y,-i-1);
	map<int,int>stoi,itos;
	sort(p,p+2*n);
	for(int i=0;i<2*n;i++)
		if(p[i].second>0)
		{
			int idx=p[i].second;
			itos[idx]=p[i].first;
			stoi[p[i].first]=idx;
		}
		else
		{
			int idx=-p[i].second;
			if(stoi.begin()->second!=idx)res++;
			stoi.erase(itos[idx]);
			itos.erase(idx);
		}
	cout<<res;
}