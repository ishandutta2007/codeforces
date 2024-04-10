#include<bits/stdc++.h>
using namespace std ;

#define li long int 
bool compare(pair<int,int> p1,pair<int,int>p2)
{
	if(p1.first==p2.first)
		return p1.second<p2.second;
	else return p1.first>p2.first;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    int n,k,i;
    cin>>n>>k;
    pair<int,int> p[n];
    for(i=0;i<n;i++)
    {
    	cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n,compare);
    int count=0;
    for(i=0;i<n;i++)
    {
    	if(p[i].first==p[k-1].first && p[i].second==p[k-1].second)
    		count++;
    }
    cout<<count;
	return 0;
}