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
    int k;
    string s;
    cin>>k>>s;
    if((s.length()%k)!=0)
    {
    	cout<<-1;return 0;
    }
    int i;
    vector<int> a(26,0);
    for(i=0;s[i];i++)
    {
    	a[s[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
    	if(a[i]%k!=0)
    	{
    		cout<<-1;return 0;
    	}
    }
    for(auto m=0;m<k;m++)
    {
    	for(i=0;i<26;i++)
    	{
    		if(a[i]!=0)
    			{
                    for(auto j=0;j<a[i]/k;j++)cout<<(char)(i+97);
    			}
    	}
    }
    return 0;
}