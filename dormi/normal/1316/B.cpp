#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        string best=a;
        int ans=1;
        for(int i=1;i<n;i++){
            string te=a;
            rotate(te.begin(),te.begin()+i,te.end());
            if((n-i)%2)reverse(te.end()-i,te.end());
            if(te<best){
                best=te;
                ans=i+1;
            }
        }
        cout<<best<<"\n"<<ans<<"\n";
    }
    return 0;
}