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
    while(t--) {
        int n;
        cin >> n;
        map<int,vector<int>> inds;
        int a;
        for (int i = 0; i < n; i++) {
            cin>>a;
            inds[a].push_back(i);
        }
        bool work=false;
        for(auto x:inds){
            if(sz(x.second)>=3){
                printf("YES\n");
                work=true;
                break;
            }
            if(sz(x.second)>=2){
                if(x.second[1]-x.second[0]>1) {
                    printf("YES\n");
                    work = true;
                    break;
                }
            }
        }
        if(!work)printf("NO\n");
    }
    return 0;
}