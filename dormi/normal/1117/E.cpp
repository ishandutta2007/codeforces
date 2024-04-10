#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e4+1;
map<string,vector<int>> matches;
map<string,vector<int>> matches2;
string at[MAXN];
int main(){
    setbuf(stdout,NULL);
    string a;
    cin>>a;
    int n=sz(a);
    string topr;
    topr.resize(n);
    for(int test=0;test<3;test++) {
        if(sz(matches)==0)for (int i = 0; i < n; i++) {
            topr[i] = (char)('a' + (i % 26));
            string te(1,topr[i]);
            matches[te].push_back(i);
        }
        else{
            for(auto x:matches){
                for(int i=0;i<sz(x.second);i++){
                    topr[x.second[i]]=(char)('a'+(i%26));
                    string te(1,topr[x.second[i]]);
                    matches2[x.first+te].push_back(x.second[i]);
                }
            }
            matches.clear();
            for(auto x:matches2)matches[x.first]=x.second;
            matches2.clear();
        }
        cout << "? " << topr << "\n";
        string in;
        cin >> in;
        if (in == "0") {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            at[i] += in[i];
        }
    }
    string ans;
    ans.resize(n);
    for(int i=0;i<n;i++){
        ans[*matches[at[i]].begin()]=a[i];
    }
    cout<<"! "<<ans<<"\n";
    return 0;
}