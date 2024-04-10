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
        pii last={0,0};
        int a,b;
        bool work=true;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(abs(last.first-a)<abs(last.second-b)||a<last.first||b<last.second){
                work=false;
            }
            last={a,b};
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}