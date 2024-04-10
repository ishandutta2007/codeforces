#include<bits/stdc++.h>
using namespace std;

int n,m,c[200005],a[15][200005];

bool cmp(const vector<int> &x,const vector<int> &y){
    int sa=0,sb=0;
    for(int i=0;i<n;i++){
        sa+=a[i][x[i]];
        sb+=a[i][y[i]];
    }
    if(sa!=sb)return sa<sb;
    return x<y;
}

struct Comp{
    bool operator()(const vector<int> &x,const vector<int> &y)const{
        return cmp(x,y);
    }
};

vector<int> ban[100005];
set<vector<int>,Comp> pq;

bool valid(const vector<int> &x){
    return *lower_bound(ban,ban+m,x,cmp)!=x;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<c[i];j++){
            cin>>a[i][j];
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        ban[i].resize(n);
        for(int &x:ban[i])cin>>x,x--;
    }
    sort(ban,ban+m,cmp);
    ban[m]=vector<int>(n,-1);
    vector<int> cur(n);
    for(int i=0;i<n;i++)cur[i]=c[i]-1;
    pq.insert(cur);
    while(!valid(cur)){
        for(int i=0;i<n;i++)if(cur[i]){
            cur[i]--;
            pq.insert(cur);
            cur[i]++;
        }
        cur=*--pq.find(cur);
    }
    for(int x:cur)cout<<x+1<<' ';

    return 0;
}