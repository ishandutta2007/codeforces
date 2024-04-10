#include <bits/stdc++.h>
using namespace std;

long long n,k;
int lastkol;
vector<long long> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=2;i<=sqrt(n);++i){
        if (lastkol==k-1) break;
        if (n%i==0) {
            while (n%i==0){
                n/=i;
                ++lastkol;
                v.push_back(i);
                if (lastkol==k-1) break;
            }
            if (lastkol==k-1) break;
        }
    }
    if (n>1) {
        ++lastkol;
        v.push_back(n);
    }
    if (lastkol!=k) {
        cout<<"-1";
        return 0;
    }
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}