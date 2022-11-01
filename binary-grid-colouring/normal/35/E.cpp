#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> >a,ans;
multiset<int>s;
 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,h;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int h,l,r;
		cin>>h>>l>>r;
		a.push_back(make_pair(l,h));
		a.push_back(make_pair(r,-h));
	}
	sort(a.begin(),a.end());
	h = 0;
	s.insert(h);
	auto it = a.begin();
	while(it!=a.end())
	{
		auto jt = it;
		do
		{
			if(jt->second > 0)
			{
				s.insert(jt->second);	
			}
			else
			{
				s.erase(s.find(-jt->second)); 
			}
			jt++;
		}while(jt != a.end() && jt->first==it->first);
		
		if(*s.rbegin() != h)
		{
			ans.push_back(make_pair(it->first,h));
			ans.push_back(make_pair(it->first,h=*s.rbegin()));
		}
		it = jt;
	}
	cout<<(int)ans.size()<<endl;
	for(int i=0;i<(int)ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
 }