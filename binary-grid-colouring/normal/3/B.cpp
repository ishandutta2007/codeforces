#include<bits/stdc++.h>
using namespace std;
int t1,t2;
int s1[100010],s2[100010];
pair<int,int>c1[100010],c2[100010];
bool cmp(pair<int,int>a,pair<int,int>b)
{
	return a.first > b. first;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,v;
	cin>>n>>v;
	for(int i=0;i<n;i++)
	{
		int t,p;
		cin>>t>>p;
		if(t==1)
		{
			c1[t1++] = make_pair(p,i+1);
		}
		else 
		c2[t2++] =make_pair(p,i+1);
	}
	sort(c1,c1+t1,cmp);
	sort(c2,c2+t2,cmp);
	s1[0] = s2[0] = 0;
	
	for(int i=0;i<t1;i++){
		s1[i+1]=s1[i]+c1[i].first;
	}
	for(int i=0;i<t2;i++){
		s2[i+1]=s2[i]+c2[i].first;
	}
	
	int ans = -1;
	int tmp = -1;
	for(int i=0;i<=t2;i++)
	{
		if(i * 2 <= v && s1[ min(v-i*2, t1) ] + s2[i]>ans){
			ans = s1[ min(v-i*2,t1) ] + s2[i] ;
			tmp = i;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<min(v-tmp*2,t1);i++) cout<<c1[i].second<<endl;
	for(int i=0;i<tmp;i++) cout<<c2[i].second<<endl;
	return 0;
}