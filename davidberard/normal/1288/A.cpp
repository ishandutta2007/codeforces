#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod=1e9+7;
#define F first
#define S second
#define _READ freopen("input.txt","r", stdin);
#define pb push_back
#define _FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main()
{
    #ifndef ONLINE_JUDGE
    _READ
    #endif
    _FAST
    lli t;
    cin>>t;
    while(t--)
    {
        lli n,d;
        cin>>n>>d;
        lli low=1,high=n*2-1,ans=-1;
        while(low<=high)
        {
            lli x=low+(high-low)/2;
            lli temp=x+(d+x)/(x+1);
            //cout<<x<<" "<<temp<<"\n";
            if(temp<=n)
            {
                ans=x;
                break;
            }
            else
            {
                high=x-1;
            }
        }
        if(ans!=-1 || n>=d)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
//g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined a.cpp -o a -D_GLIBCXX_DEBUG