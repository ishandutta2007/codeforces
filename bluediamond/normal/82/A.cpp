#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int n,s=0,cur=1;

string call(int x)
{
    if(x==1) return "Sheldon";
    if(x==2) return "Leonard";
    if(x==3) return "Penny";
    if(x==4) return "Rajesh";
    if(x==5) return "Howard";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    while(s+cur*5<n)
    {
        s+=cur*5;
        cur*=2;
    }
    n-=s;
    n--;
    cout<<call(1+n/cur)<<"\n";
    return 0;
}
/**


**/