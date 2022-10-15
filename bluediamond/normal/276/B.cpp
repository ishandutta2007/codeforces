#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ap[30];
string a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        ap[a[i]-'a']++;
    }
    int cnt=0;
    for(int i=0;i<26;i++)
        if(ap[i]%2==1)
        {
            cnt++;
        }
    string p1,p2;
    p1="First";
    p2="Second";
    if(cnt<=1)
        cout<<p1;
    else
    {
        if((cnt-2)%2==1)
            cout<<p1;
        else
            cout<<p2;
    }
    cout<<"\n";
    return 0;
}
/**

**/