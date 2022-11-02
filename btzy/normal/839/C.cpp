#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
unsigned n;
vector<unsigned> adj[100001];
double get_expected_probability(unsigned curr,unsigned prev){
    unsigned ct=0;
    double sum=0.0;
    for(unsigned x:adj[curr]){
        if(x!=prev){
            sum+=get_expected_probability(x,curr);
            ++ct;
        }
    }
    if(ct==0)return 0.0;
    sum/=static_cast<double>(ct);
    return sum+1.0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(unsigned i=1;i<n;++i){
        unsigned u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cout<<fixed<<setprecision(12)<<get_expected_probability(1,0)<<endl;
}