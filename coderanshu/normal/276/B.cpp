#include<bits/stdc++.h>
using namespace std ;
int main(int argc, char const *argv[])
{

    //freopen("inputf.in", "r", stdin);
    //freopen("outputf.in", "w", stdout);

    int k,i,odds=0,f,j;
    string s;
    cin>>s;
    k=s.length();
    for(i=0;i<k;i++)
    {
    	f=0;
    	if(s[i]!='0')
    	{
    		f++;
    		for(j=i+1;j<k;j++)
    		{
    			if(s[i]==s[j])
    			{
    				s[j]='0';f++;
    			}
    		}
    		if(f%2)odds++;
    	}
    }
    if(odds==0 || odds%2)
    	cout<<"First";
    else cout<<"Second";
	return 0;
}