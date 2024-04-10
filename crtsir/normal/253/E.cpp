#include<bits/stdc++.h>
using namespace std;
map<long long,long long>ret;
vector<pair<long long,int> >v;
pair<long long,long long>tmp[50003];
vector<pair<long long,pair<long long,long long> > >t;
long long len[50003],tim[50003],p[50003],n,T,x,y,jl;
void check(long long sth)
{
	t.clear();
	ret.clear();
	t.push_back(make_pair(x,make_pair(y,sth)));
	for(int i=0;i<n-1;i++)
		t.push_back(make_pair(tim[i],make_pair(len[i],p[i])));
	sort(t.begin(),t.end());
	priority_queue<pair<long long,long long> >q;
	long long go=t[0].first;
	for(int i=0;i<t.size()-1;i++)
	{
		q.push(make_pair(t[i].second.second,t[i].second.first));
		long long cango=t[i+1].first-t[i].first;
		while(!q.empty()&&cango)
			if(q.top().second<=cango)
			{
				cango-=q.top().second;
				ret[q.top().first]=t[i+1].first-cango;
				q.pop();
			}
			else
			{
				pair<long long,long long>msc
				=make_pair(q.top().first,q.top().second-cango);
				q.pop();
				q.push(msc);
				cango=0;
			}
		go=t[i+1].first;
	}
	q.push(make_pair(t[t.size()-1].second.second,t[t.size()-1].second.first));
	while(!q.empty())
	{
		go+=q.top().second;
		ret[q.top().first]=go;
		q.pop();
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0,j=0;j<n;i++,j++)
	{
		cin>>tim[i]>>len[i]>>p[i];
		if(p[i]==-1)
			x=tim[i],
			y=len[i],
			jl=i,
			i--;
		else
			tmp[i]=make_pair(p[i],i);
	}
	cin>>T;
	sort(tmp,tmp+n-1);
    if(tmp[0].first>1)v.push_back(make_pair(1,0));
	for(int i=0;i<n-2;i++)
		if(tmp[i+1].first-tmp[i].first>1)
			v.push_back(make_pair(tmp[i].first+1,i+1));
	v.push_back(make_pair(tmp[n-2].first+1,n-1));
	long long l=0,r=v.size();
	while(1)
	{
		long long mid=(l+r)/2;
		check(v[mid].first);
		if(ret[v[mid].first]==T)
			break;
		if(ret[v[mid].first]>T)
			l=mid+1;
		else
			r=mid;
	}
	cout<<v[(l+r)/2].first<<endl;
    for(int i=0;i<jl;i++)cout<<ret[p[i]]<<" ";
    cout<<ret[v[(l+r)/2].first];
    for(int i=jl;i<n-1;i++)cout<<' '<<ret[p[i]];
}