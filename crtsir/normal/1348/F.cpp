#include<bits/stdc++.h>
using namespace std;vector<pair<int,int> >v[200003];
int n,ans[200003],a[200003],b[200003],res[262144];
pair<int,int>dat[524288];
pair<int,int>query(int x,int y,int a,int b,int k)
{
	if(x<=a&&b<=y)
		return dat[k];
	if(a>y||b<x)
		return make_pair(0,233);
	return max(query(x,y,a,(a+b)/2,k*2),query(x,y,(a+b)/2+1,b,k*2+1));
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",a+i,b+i);
		a[i]--;
		b[i]--;
		v[b[i]].push_back(make_pair(a[i],i));
	}
	priority_queue<pair<int,int> >q;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<v[i].size();j++)
			q.push(v[i][j]);
		ans[q.top().second]=i;q.pop();
	}
	memset(res,-1,sizeof(res));
	for(int i=0;i<n;i++)
		res[ans[i]]=i;
//	for(int i=0;i<n;i++)cout<<res[i]<<' ';cout<<endl;
//	for(int i=0;i<n;i++)cout<<ans[i]<<' ';cout<<endl;
	for(int i=0;i<n;i++)
		dat[i+262144]=make_pair(b[res[i]],res[i]);
	for(int i=262143;i>=1;i--)
		dat[i]=max(dat[i*2],dat[i*2+1]);
	for(int i=1;i<n;i++){
		if(a[res[i]]==i)
			continue;
		pair<int,int>maxn=query(a[res[i]],i-1,0,262143,1);
		if(maxn.first>=i){
			cout<<"NO\n";
			for(int j=0;j<n;j++)
				printf("%d ",ans[j]+1);cout<<endl;
			swap(ans[res[i]],ans[maxn.second]);
			for(int j=0;j<n;j++)
				printf("%d ",ans[j]+1);
			return 0;
		}
	}
	cout<<"YES\n";
	for(int j=0;j<n;j++)
		printf("%d ",ans[j]+1);cout<<"\n";
}