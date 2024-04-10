#include<bits/stdc++.h>
using namespace std ;

#define li long int
#define modulo 1000000007 

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
     string s;
     cin>>s;
     long int k,n,i,j,z;
     pair<char,long int>p[200000];
     k=0;
     n=s.length();
     for(i=0;i<n;i++)
     {
        j=i+1;
        while(s[j]==s[i] && j<n)j++;
        p[k].first=s[i];p[k].second=j-i;
        k++;
        i=j-1;
     }
     if(p[0].second>=2 && p[1].second>=2)
        p[0].second=2;
     else if(p[0].second>2)
        p[0].second=2;
     for(z=1;z<k-1;z++)
     {
        if((p[z-1].second>=2 || p[z+1].second>=2)&&p[z].second>=2)
            p[z].second=2;
        else if(p[z].second>2)
            p[z].second=2;
     }
     if(p[k-2].second>=2 && p[k-1].second>=2)
        p[k-1].second=2;
    else if(p[k-1].second>2)
        p[k-1].second=2;
     for(z=1;z<k;z++)
     {
        if(p[z-1].second==2)
            p[z].second=1;
     }
     for(z=0;z<k;z++)
     {
        while(p[z].second--)
            cout<<p[z].first;
     }
	return 0;
}