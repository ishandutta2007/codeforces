#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int n;

string sol="";

int cif[10],y=0;

void add(int nr)
{
    y=0;
    while(nr>0)
    {
        cif[++y]=nr%10;
        nr/=10;
    }
    for(int i=y;i>=1;i--)
        sol+=('0'+cif[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=1000;i++)
        add(i);
    cout<<sol[n-1]<<"\n";
    return 0;
}
/**
**/