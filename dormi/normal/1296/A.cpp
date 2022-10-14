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
        int n;
        cin>>n;
        int par[2]={};
        int sum=0;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            sum+=a;
            par[a%2]++;
        }
        if(sum%2){
            printf("YES\n");
        }
        else if(par[0]&&par[1])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}