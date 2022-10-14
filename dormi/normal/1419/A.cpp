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
        int n;
        cin>>n;
        string a;
        cin>>a;
        int oddcnt=0;
        for(int i=1;i<=n;i++){
            if(n%2==i%2&&(a[i-1]-'0')%2==1)oddcnt++;
        }
        if(n%2==1){
            if(oddcnt){
                printf("1\n");
            }
            else printf("2\n");
        }
        else{
            if(oddcnt==n/2)printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}