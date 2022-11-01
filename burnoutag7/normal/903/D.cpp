#include<bits/stdc++.h>
using namespace std;

int n,t;
long double p,a;
map<int,int> mp;

int main(){
    cin>>n;
    for(int i=0;i++<n;){
        cin>>t;
        p+=t;mp[t]++;
        a+=(long double)i*t-mp[t-1]+mp[t+1]-p;
    }
    cout<<fixed<<setprecision(0)<<a<<endl;
    return 0;
}