#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            string a;
            cin>>a;
            if(a!="B"&&a!="W"&&a!="G"){
                printf("#Color\n");
                return 0;
            }
        }
    }
    printf("#Black&White\n");
    return 0;
}