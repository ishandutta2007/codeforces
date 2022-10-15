#include <bits/stdc++.h>

using namespace std;

string ask(int p)
{
    cout<<p<<" "<<1<<endl;
    string s;
    cin>>s;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string a=ask(0);
    int lo=1;
    int hi=1000000000;
    for(int i=1;i<n;i++)
    {
        int mid=(lo+hi)/2;
        if(ask(mid)==a)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    cout<<lo-1<<" "<<0<<" "<<lo<<" "<<2<<"\n";
    return 0;
}