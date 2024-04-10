#include<bits/stdc++.h>
using namespace std ;

#define li long int 

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    pair<long int,int> p[400000];
    long int n,num,m,i,k=0,c1=0,c2=0;
    cin>>n;
    for (i = 0; i < n;i++)
    {
    	cin>>num;
    	p[k].first=num;p[k].second=1;k++;
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
    	cin>>num;
    	p[k].first=num;p[k].second=2;k++;
    }
    sort(p,p+n+m);
    //for(i=0;i<n+m;i++)
    //	cout<<p[i].first<<" "<<p[i].second<<" ";
    long long int ans1=3*n,ans2=3*m;
    for(i=0;i<n+m;i++)
    {
    	if(p[i].second==1)
    	{
    		if(c2>c1)
    		{
    			ans1-=c1;
    			ans2-=c2;
    			c2=0;c1=1;
    		}
    		else c1++;
    	}
    	else c2++;
    }
    if(c2>c1)
    {
    ans1-=c1;ans2-=c2;
    }
    cout<<ans1<<":"<<ans2;
	return 0;
}