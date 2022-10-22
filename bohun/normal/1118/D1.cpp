#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m;
int t[200009];
int ile[200009];
ll co[200009];
ll sum;
bool f(ll x)
{
	ll wynik=0;
	for(int i=1;n+5>=i;i++)
	{
		ile[i]=0;
		co[i]=0;
	}
	for(int i=1;n>=i;i++)
	{
		co[i%x+1]++;
	}
	for(int i=1;n>=i;i++)
	{
		co[i%x+1]--;
		if(t[i]-ile[i%x+1]>=co[i%x+1])
		{
			wynik+=t[i]-ile[i%x+1];
			ile[i%x+1]++;
		}
	}
	return wynik>=m;
}
int main(){
	cin>>n>>m;
	for(int i=1;n>=i;i++)
	{
		cin>>t[i];
		sum+=t[i];
	}
	if(sum<m)
	{
		cout<<-1;
		return 0;
	}
	t[n+1]=1000000005;
	sort(t+1,t+n+1);	
	ll lewo=1;
	ll prawo=n+1;
	while(prawo>lewo)
	{
		ll mid=(lewo+prawo)/2;
		if(f(mid)==1)
			prawo=mid;
		else
			lewo=mid+1;
	}
	if(lewo==n+1)
		cout<<-1;
	else
		cout<<lewo;
	
    return 0;
}