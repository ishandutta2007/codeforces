#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=501;
lli arr[MAXN];
lli ree[1001];
int ffs[1001];
int last[MAXN];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    lli ans=0;
    for(int i=1;i<=m;i++){
        cin>>a;
        ffs[i]=a;
        set<int> done;
        for(int j=last[a]+1;j<i;j++){
            if(!done.count(ffs[j])){
                done.insert(ffs[j]);
                ans+=arr[ffs[j]];
            }
        }
        last[a]=i;
    }
    printf("%lli\n",ans);
    return 0;
}