#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<pair<int,pair<int,pii>>> matrix[MAXN];
int ans[MAXN];
int n,m,q;
bitset<1001> arr[1001];
int extra[1001];
int tot=0;
int oth(int a){
    if(a==0)return 1001-m;
    else return 0;
}
void dfs(int loc){
    ans[loc]=tot;
    for(auto x:matrix[loc]){
        if(x.second.first==1){
            bool prev=arr[x.second.second.first][x.second.second.second];
            if(!prev)tot++;
            arr[x.second.second.first][x.second.second.second]=true;
            dfs(x.first);
            if(!prev)tot--;
            arr[x.second.second.first][x.second.second.second]=prev;
        }
        else if(x.second.first==2){
            bool prev=arr[x.second.second.first][x.second.second.second];
            if(prev)tot--;
            arr[x.second.second.first][x.second.second.second]=false;
            dfs(x.first);
            if(prev)tot++;
            arr[x.second.second.first][x.second.second.second]=prev;
        }
        else if(x.second.first==3){
            int bits=arr[x.second.second.first].count()-extra[x.second.second.first];
            tot-=bits;
            tot+=m-bits;
            arr[x.second.second.first].flip();
            extra[x.second.second.first]=oth(extra[x.second.second.first]);
            dfs(x.first);
            arr[x.second.second.first].flip();
            extra[x.second.second.first]=oth(extra[x.second.second.first]);
            tot+=bits;
            tot-=m-bits;
        }
        else{
            dfs(x.first);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>q;
    int a,b,c;
    for(int i=1;i<=q;i++){
        cin>>a>>b;
        if(a==1){
            cin>>c;
            matrix[i-1].push_back({i,{a,{b,c}}});
        }
        else if(a==2){
            cin>>c;
            matrix[i-1].push_back({i,{a,{b,c}}});
        }
        else if(a==3){
            matrix[i-1].push_back({i,{a,{b,0}}});
        }
        else{
            matrix[b].push_back({i,{a,{0,0}}});
        }
    }
    dfs(0);
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}