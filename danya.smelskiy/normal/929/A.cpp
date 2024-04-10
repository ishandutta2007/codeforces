#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int x[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int pos=1,kol=1;
    for (int i=1; i<=n; i++)
        cin>>x[i];
    for (int i=2; i<=n; i++)
        if (x[i]-x[pos]>k)
    {
        if (pos==i-1) {cout<<"-1"<<endl; return 0;}
        kol++;
        pos=i-1;
        if (x[i]-x[pos]>k) {cout<<"-1"<<endl; return 0;}
    }
    cout<<kol<<endl;
}