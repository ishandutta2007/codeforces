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
        string a;
        cin>>a;
        int last=-1;
        int ma=0;
        for(int i=0;i<sz(a);i++){
            if(a[i]=='R'){
                ma=max(ma,i-last);
                last=i;
            }
        }
        ma=max(ma,sz(a)-last);
        printf("%d\n",ma);
    }
    return 0;
}