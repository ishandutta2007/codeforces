#include <bits/stdc++.h>
using namespace std;
long long n,k;
vector<long long> v;
vector<long long> v2;

int main(){
    cin>>n>>k;
    v.push_back(1);
    for (int i=2;i<=sqrt(n);++i){
        if (n%i==0){
            v.push_back(i);
            if(i!=n/i) v.push_back(n/i);
        }
    }
    if (n>1)
    v.push_back(n);
    if (v.size()<k) cout<<"-1";
    else {
        sort(v.begin(),v.end());
        cout<<v[k-1];
    }
}