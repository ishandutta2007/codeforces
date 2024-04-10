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
       lli n,k;
       cin>>n>>k;
       if(n%2==k%2&&n>=k*k)printf("YES\n");
       else printf("NO\n");
    }
    return 0;

}