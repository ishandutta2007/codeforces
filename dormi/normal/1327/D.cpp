#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int arr[MAXN];
int colour[MAXN];
vector<int> cycles;
bool gone[MAXN];
int am[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cycles.clear();
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            gone[i]=false;
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)cin>>colour[i];
        for(int i=1;i<=n;i++){
            if(!gone[i]){
                cycles.clear();
                int cur=arr[i];
                cycles.push_back(colour[i]);
                gone[i]=true;
                while(!gone[cur]){
                    cycles.push_back(colour[cur]);
                    gone[cur]=true;
                    cur=arr[cur];
                }
                int n=sz(cycles);
                for(int j=1;j<=sqrt(n);j++){
                    if(n%j==0){
                        for(int k=0;k<j;k++)am[k]=-1;
                        for(int k=0;k<n;k++){
                            if(am[k%j]==-1)am[k%j]=cycles[k];
                            else if(am[k%j]!=cycles[k])am[k%j]=INT_MAX;
                        }
                        for(int k=0;k<j;k++){
                            if(am[k]!=INT_MAX)ans=min(ans,j);
                        }
                        int oldj=j;
                        j=n/j;
                        for(int k=0;k<j;k++)am[k]=-1;
                        for(int k=0;k<n;k++){
                            if(am[k%j]==-1)am[k%j]=cycles[k];
                            else if(am[k%j]!=cycles[k])am[k%j]=INT_MAX;
                        }
                        for(int k=0;k<j;k++){
                            if(am[k]!=INT_MAX)ans=min(ans,j);
                        }
                        j=oldj;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}