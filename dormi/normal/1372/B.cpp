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
        if(n%2==0)printf("%d %d\n",n/2,n/2);
        else{
            int mi=INT_MAX;
            for(int i=1;i*i<=n;i++){
                if(n%i==0){
                    if(n/i>1)mi=min(mi,(n/i-1)*i);
                    if(i>1)mi=min(mi,(n/i)*(i-1));
                }
            }
            printf("%d %d\n",n-mi,mi);
        }
    }
    return 0;
}
//x+ax=n
//(a+1)x=n\