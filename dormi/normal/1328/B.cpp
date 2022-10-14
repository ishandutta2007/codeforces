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
        lli k;
        cin>>n>>k;
        lli cur=1;
        k-=1;
        while(k>=cur){
            k-=cur;
            cur++;
        }
        int i=0;
        for(;i<n-cur-1;i++){
            printf("a");
        }
        printf("b");
        i++;
        for(;i<n-k-1;i++)printf("a");
        printf("b");
        i++;
        for(;i<n;i++)printf("a");
        printf("\n");
    }
    return 0;
}