#include <bits/stdc++.h>

using namespace std;

vector<int> Out;
bool P[500000];

int main() {
    int n;
    cin>>n;

    for(int i=2; i<=n; i++) {
        if(P[i]) continue;
        for(int j=i+i; j<=n; j+=i) P[j] = 1;

        for(int t=i; t<=n; t*=i) {
            Out.push_back(t);
        }

    }

    cout<<Out.size()<<'\n';
    for(auto out : Out) cout<<out<<" ";
}