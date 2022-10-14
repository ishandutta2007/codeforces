#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1,MAXV=5e5+1;
bool in[MAXN];
vector<int> nums[MAXN];
map<int,int> type;
map<int,int> am;
int arr[MAXN];
ll ans=0;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        in[i]=false;
        vector<int> te;
        for(int j=2;j*j<=arr[i];j++){
            bool p=false;
            while(arr[i]%j==0){
                p=true;
                arr[i]/=j;
            }
            if(p)te.push_back(j);
        }
        if(arr[i]>1)te.push_back(arr[i]);
        nums[i].push_back(1);
        type[1]=1;
        for(int j=1;j<(1<<sz(te));j++){
            int prod=1;
            int pcnt=1;
            for(int k=0;k<sz(te);k++){
                if(j&(1<<k)){
                    prod*=te[k];
                    pcnt*=-1;
                }
            }
            type[prod]=pcnt;
            nums[i].push_back(prod);
        }
    }
    int a;
    while(q--){
        cin>>a;
        a--;
        int mut=(in[a]?-1:1);
        for(auto x:nums[a]){
            if(in[a])am[x]+=mut;
            ans+=mut*type[x]*am[x];
            if(!in[a])am[x]+=mut;
        }
        in[a]=!in[a];
        printf("%lli\n",ans);
    }
    return 0;
}