#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s.size()==2)
        {
            if(s[0]<s[1]) cout<<"YES\n2\n"<<s[0]<<" "<<s[1]<<"\n";
            else cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n2\n"<<s[0]<<" ";
            for(int a=1; a<s.size(); a++) cout<<s[a];
            cout<<"\n";
        }
    }
}