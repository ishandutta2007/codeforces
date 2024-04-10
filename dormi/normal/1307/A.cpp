#include<bits/stdc++.h>
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
        int n,d;
        cin>>n>>d;
        int curam;
        cin>>curam;
        for(int i=1;i<n;i++){
            int am;
            cin>>am;
            int use=min(am,d/i);
            curam+=use;
            d-=i*use;
        }
        printf("%d\n",curam);
    }
    return 0;
}