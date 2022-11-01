#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int len,n,g,r;
int pos[10005];
int d[10005][1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>len>>n;
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }
    sort(pos,pos+n);
    cin>>g>>r;

    memset(d,-1,sizeof(d));
    d[0][g]=0;
    deque<pair<int,int>> q;
    q.emplace_back(0,g);
    while(!q.empty()){
        int x=q.front().first,c=q.front().second;
        q.pop_front();
        if(x){
            int cd=pos[x]-pos[x-1];
            if(c>cd){
                if(d[x-1][c-cd]==-1){
                    d[x-1][c-cd]=d[x][c];
                    q.emplace_front(x-1,c-cd);
                }
            }else if(c==cd){
                if(d[x-1][g]==-1){
                    d[x-1][g]=d[x][c]+1;
                    q.emplace_back(x-1,g);
                }
            }
        }
        if(x+1<n){
            int cd=pos[x+1]-pos[x];
            if(c>cd){
                if(d[x+1][c-cd]==-1){
                    d[x+1][c-cd]=d[x][c];
                    q.emplace_front(x+1,c-cd);
                }
            }else if(c==cd){
                if(d[x+1][g]==-1){
                    d[x+1][g]=d[x][c]+1;
                    q.emplace_back(x+1,g);
                }
            }
        }
    }

    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<n;i++)if(d[i][g]!=-1&&len-pos[i]<=g)ans=min(ans,(ll)d[i][g]*(g+r)+len-pos[i]);
    cout<<(ans==0x3f3f3f3f3f3f3f3f?-1:ans)<<endl;

    return 0;
}