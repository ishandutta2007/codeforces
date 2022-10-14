#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<string> ree;
vector<string> use;
vector<string> spec;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string a;
    int len=0;
    for(int i=0;i<n;i++){
        cin>>a;
        string te=a;
        reverse(a.begin(),a.end());
        if(te==a&&sz(spec)==0){
                spec.push_back(te);
                len += m;
        }
        else {
            if (ree.count(a)) {
                use.push_back(a);
                ree.erase(a);
                reverse(a.begin(), a.end());
                use.push_back(a);
                len += 2 * m;
            } else {
                reverse(a.begin(), a.end());
                ree.insert(a);
            }
        }
    }
    cout<<len<<"\n";
    for(int i=0;i<sz(use);i+=2){
        cout<<use[i];
    }
    for(string x:spec)cout<<x;
    for(int i=(sz(use)-1);i>=1;i-=2){
        cout<<use[i];
    }
    return 0;
}