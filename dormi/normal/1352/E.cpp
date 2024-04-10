#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=8001;
int arr[MAXN];
bool poss[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)poss[i]=false;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            arr[i]+=arr[i-1];
            for(int j=0;j<=i-2;j++){
                if(arr[i]-arr[j]<=n)poss[arr[i]-arr[j]]=true;
            }
        }
        int spec=0;
        for(int i=1;i<=n;i++){
            if(poss[arr[i]-arr[i-1]])spec++;
        }
        printf("%d\n",spec);
    }
    return 0;
}