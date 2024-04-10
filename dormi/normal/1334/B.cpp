#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
lli arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        lli x;
        cin>>n>>x;
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n,greater<>());
        lli sum=0;
        bool work=true;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum/(lli)(i+1)<x){
                printf("%d\n",i);
                work=false;
                break;
            }
        }
        if(work){
            printf("%d\n",n);
        }
    }
    return 0;
}