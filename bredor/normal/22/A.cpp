//  228

#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define OO +1e9
#define fi first
#define se second
#define pb push_back
#define Morad ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fr(i,n) for(i=0;i<n;i++)

using namespace std;
//Done By The MORAD
ll t=1,n,k,i;
ll a[1010];
int main ()
{
    Morad
    //cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);
        bool b=0;
        for(i=0; i<n-1; i++)
        {

            if(a[i]!=a[i+1])
            {
                b=1;
                cout<<a[i+1]<<endl;

                break;
            }
        }
        if(!b)
            no
        }
    return 0;
}