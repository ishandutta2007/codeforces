#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int pos[MN][2];
int col[2][MN];
bool gone[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>col[0][i],pos[col[0][i]][0]=i,gone[i]=false;
        for(int i=1;i<=n;i++)cin>>col[1][i],pos[col[1][i]][1]=i;
        vector<int> lens;
        for(int i=1;i<=n;i++){
            if(!gone[i]){
                gone[i]=true;
                int cur=pos[col[1][i]][0];
                int cnt=1;
                while(cur!=i){
                    gone[cur]=true;
                    cnt++;
                    cur=pos[col[1][cur]][0];
                }
                lens.push_back(cnt);
            }
        }
        sort(lens.begin(),lens.end(),greater<>());
        int left=n;
        ll val=0;
        for(auto x:lens){
            int original=left;
            for(int i=1;i<x;i++){
                val+=left-1;
                left--;
            }
            if(x%2==0){
                left--;
                val+=original-1-(x/2-1);
            }
            else{
                val+=x/2;
            }
        }
        printf("%lli\n",val);
    }
    return 0;
}