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
        int n;
        cin>>n;
        int mod[2]={};
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            mod[a%2]++;
        }
        if(mod[0]&&mod[1])printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}