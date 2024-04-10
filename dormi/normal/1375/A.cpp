#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            a=abs(a);
            if(i%2==0)printf("%d ",a);
            else printf("%d ",a*-1);
        }
        printf("\n");
    }
    return 0;
}