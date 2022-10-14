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
        int n,m;
        cin>>n>>m;
        int sum=0;
        int a=0;
        for(int i=0;i<n;i++){
            cin>>a;
            sum+=a;
        }
        printf("%d\n",min(sum,m));
    }
    return 0;
}