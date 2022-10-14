#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=4001;
int arr[MAXN];
bool poss[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int le=0;
        vector<int> lens;
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
            if(arr[i]>arr[le]){
                lens.push_back(i-le);
                le=i;
            }
        }
        lens.push_back(2*n-le);
        poss[0][0]=true;
        for(int i=1;i<=n;i++)poss[0][i]=false;
        for(int j=1;j<=sz(lens);j++){
            for(int k=0;k<=n;k++){
                poss[j][k]=poss[j-1][k];
                if(k-lens[j-1]>=0)poss[j][k]|=poss[j-1][k-lens[j-1]];
            }
        }
        if(poss[sz(lens)][n])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}