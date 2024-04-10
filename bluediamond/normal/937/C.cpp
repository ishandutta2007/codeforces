#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll k,d,t;
ll ans;
int main()
{
    cin>>k>>d>>t;
    k*=2; t*=2; d*=2; /// *2 pentru a nu avea probleme cu virgula
    ll NXT;///urmatorul multiplu de d dupa k
    if(k%d==0)
        NXT=k;
    else
        NXT=k/d*d+d;
    ll scad_tura,timp_tura;///cu cat scad pe tura
    scad_tura=(k+(NXT-k)/2);
    timp_tura=NXT;
    ll nr_ture;///cate ture facem
    nr_ture=t/scad_tura;
    ans+=nr_ture*timp_tura;///ans creste
    ll ramas=t%scad_tura;
    if(ramas<=k)
    {
        ans+=ramas;
    }
    else
    {
        ans+=k;
        ramas-=k;
        ans+=2*ramas;
    }
    cout<<ans/2;
    if(ans%2)
        cout<<".5";
    return 0;
}
/**


**/