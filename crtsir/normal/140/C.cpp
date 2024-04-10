#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >q;
int n,a[100003];
vector<pair<int,pair<int,int> > >ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;)
	{
		int j=i;
		while(j<n&&a[j]==a[i])j++;
		q.push(make_pair(j-i,a[i]));
		i=j;
	}
	while(q.size()>2)
	{
		pair<int,int>x1=q.top();q.pop();
		pair<int,int>x2=q.top();q.pop();
		pair<int,int>x3=q.top();q.pop();
		x1.first--;x2.first--;x3.first--;
		int c[3]={x1.second,x2.second,x3.second};
		sort(c,c+3);
		ans.push_back(make_pair(c[2],make_pair(c[1],c[0])));
		if(x1.first)q.push(x1);
		if(x2.first)q.push(x2);
		if(x3.first)q.push(x3);
	}
	cout<<ans.size();
	for(int i=0;i<ans.size();i++)
		cout<<endl<<ans[i].first<<' '<<ans[i].second.first<<' '<<ans[i].second.second;
}