#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t)
    {
        t--;
        string s;
        cin>>s;
        int l=0;
        while(l<s.size() and s[l]=='0') l++;
        int r=s.size()-1;
        while(r>=0 and s[r]=='0') r--;
        int an=0;
        for(l; l<=r; l++) an+=(s[l]=='0');
        cout<<an<<"\n";
    }
}