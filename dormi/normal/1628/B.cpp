#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
string arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool work=false;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(sz(arr[i])==1)work=true;
            string te=arr[i];
            reverse(te.begin(),te.end());
            if(te==arr[i])work=true;
        }
        if(work){
            printf("YES\n");
            continue;
        }
        set<string> has2,has3,has3total;
        for(int i=n;i>=1;i--){
            if(sz(arr[i])==3){
                if(has2.count(arr[i].substr(0,2))){
                    work=true;
                    break;
                }
                if(has3total.count(arr[i])){
                    work=true;
                    break;
                }
                string te=arr[i].substr(1,2);
                reverse(te.begin(),te.end());
                has3.insert(te);
                te=arr[i];
                reverse(te.begin(),te.end());
                has3total.insert(te);
            }
            else{
                if(has2.count(arr[i])||has3.count(arr[i])){
                    work=true;
                    break;
                }
                string te=arr[i];
                reverse(te.begin(),te.end());
                has2.insert(te);
            }
        }
        if(work){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}