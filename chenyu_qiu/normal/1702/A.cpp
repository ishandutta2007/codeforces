#include <iostream>
#include<bits/stdc++.h>
#include<string>
 
 
#include <iomanip>
#include<math.h>
typedef long long int ll;
#define MAX 100000000
using namespace std;
#include<iomanip>
//Compiler version g++ 6.3.0
bool isprime(ll n);
vector<ll> p(1000,1);
vector<ll> l;
int main() {
ll t,n;cin>>t;
while(t--)
{
    cin>>n;
    ll x=0;
    ll y=n;
    while(y>0)
    {
        x++;
        y/=10;
    }
    ll num=pow(10,x-1);
    cout<<n-num<<endl;
}
 
return 0;
}