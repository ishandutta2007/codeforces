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
        lli n,k;
        cin>>n>>k;
        lli mo=n%k;
        lli mi=max((lli)0,mo-k/2);
        printf("%lli\n",n-mi);
    }
    return 0;
}