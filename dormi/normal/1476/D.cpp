#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
int ans[MN];
int othans[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        for(int i=0;i<=n;i++)ans[i]=othans[i]=0;
        for(int i=0;i<=n;i++){
            if(a[i]=='R'){
                ans[i]=-1;
                for(int j=i+1;j<n;j++){
                    if(a[j]!=((j-i)%2==1?'L':'R')){
                        ans[i]=j-i;
                        break;
                    }
                }
                if(ans[i]==-1)ans[i]=n-i;
                for(int j=i+2;j<i+ans[i];j+=2){
                    ans[j]=ans[j-2]-2;
                }
                i=ans[i]+i-1;
            }
        }
        for(int i=n;i>=0;i--){
            if(a[i-1]=='L'){
                othans[i]=-1;
                for(int j=i-1;j>0;j--){
                    if(a[j-1]!=((i-j)%2==1?'R':'L')){
                        othans[i]=i-j;
                        break;
                    }
                }
                if(othans[i]==-1)othans[i]=i;
                for(int j=i-2;j>i-othans[i];j-=2){
                    othans[j]=othans[j+2]-2;
                }
                i=i-othans[i]+1;
            }
        }
        for(int i=0;i<=n;i++)printf("%d%c",1+ans[i]+othans[i]," \n"[i==n]);
    }
    return 0;
}