#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;

int n;
int top;
int a[N],b[N];

int inv(int x)
{
    return 7-x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>top;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        int s=6*7/2;
        s-=a[i]; s-=inv(a[i]);
        s-=b[i]; s-=inv(b[i]);
        s-=top;
        if(inv(s)!=top || top==a[i] || top==inv(a[i]) || top==b[i] || top==inv(b[i]))
        {
            cout<<"NO\n";
            return 0;
        }
     //   cout<<s<<" : "<<top<<"\n";
        top=s;
    }
    cout<<"YES\n";
    return 0;
}
/**

**/