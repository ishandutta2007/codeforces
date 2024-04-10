#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> pieces(n);
        for(int i=0;i<n;i++){
            cin>>pieces[i];
        }
        int sum=0;
        vector<int> ord;
        bool poss=true;
        for(int i=0;i<n;i++){
            sum+=pieces[i];
            if(sum==x){
                if(i==n-1){
                    poss=false;
                }
                else{
                    ord.push_back(pieces[i+1]);
                    ord.push_back(pieces[i]);
                    i++;
                }
            }
            else ord.push_back(pieces[i]);
        }
        if(poss){
            printf("YES\n");
            for(auto y:ord)printf("%d ",y);
            printf("\n");
        }
        else printf("NO\n");
    }
    return 0;
}