#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int n;
int X[N],Y[N];
vector<pair<int,int> > XL[N],YL[N];
bool rob=false;
char ans[N*3];
bool flag[N*3];
void dfs(int v, int c) {
    if(c==0){
        while(!XL[v].empty()){
            auto p=XL[v].back();
            int x=p.F,y=p.S;
            XL[v].pop_back();
            if(flag[y]) continue;
            flag[y]=true;
            dfs(x,1-c);
            if(rob) ans[y]='b';
            else ans[y]='r';
            rob=!rob;
        }
    }else{
        while(!YL[v].empty()){
            auto p=YL[v].back();
            int x=p.F,y=p.S;
            YL[v].pop_back();
            if(flag[y]) continue;
            flag[y]=true;
            dfs(x,1-c);
            if(rob) ans[y]='b';
            else ans[y]='r';
            rob=!rob;
        }
    }
}

int main() {
    fast_io;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> X[i] >> Y[i];
    for(int i=0; i<n; i++){
        XL[X[i]].emplace_back(Y[i],i);
        YL[Y[i]].emplace_back(X[i],i);
    }
    int k=n+1;
    for(int i=0; i<N; i++){
        if(XL[i].size()%2==1){
            XL[i].emplace_back(N-1,k);
            YL[N-1].emplace_back(i,k++);
        }
        if(YL[i].size()%2==1){
            YL[i].emplace_back(N-1,k);
            XL[N-1].emplace_back(i,k++);
        }
    }
    for(int i=0; i<N; i++){
        if(!XL[i].empty()){
            dfs(i,0);
        }
        if(!YL[i].empty()){
            dfs(i,1);
        }
    }
    for(int i=0; i<n; i++) cout << ans[i];
    return 0;
}