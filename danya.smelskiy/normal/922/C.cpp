#include <bits/stdc++.h>
using namespace std;


long long n,m;
map<long long,bool> used;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    long long x;
    for (long long i=1;i<=min(10000ll,m);++i) {
        x=n%i;
        if (used[x]) {
            cout<<"No";
            return 0;
        }
        used[x]=true;
    }
    cout<<"Yes";
}