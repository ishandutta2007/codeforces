#include<bits/stdc++.h>
using namespace std;
int n,k;
pair<int,int>d[100003];
string s,t;
int main(){
	cin>>n>>k>>s;
	t=s;
	pair<int,string>ans=make_pair(123123,"");
	for(int i=0;i<10;i++)
	{
		s=t;
		for(int j=0;j<n;j++)
			d[j]=make_pair(abs(s[j]-i-'0'),s[j]-'0'>=i?-n+j:n-j);
		sort(d,d+n);
		int cost=0;
		for(int j=0;j<k;j++)
		{
			cost+=d[j].first;
			if(d[j].second>0)
				d[j].second*=-1;
			s[d[j].second+n]=i+'0';
		}
		//cout<<cost<<' '<<s;
		ans=min(ans,make_pair(cost,s));
	}
	cout<<ans.first<<endl<<ans.second;
}