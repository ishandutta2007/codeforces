#include <bits/stdc++.h>

using namespace std;

const int N=1000000;
int n,root;
int t[N+5],kek[N+5];
vector<int>v[N+5];
int sum[N+5];
int who[N+5];
int val;

void build1(int nod) {
    sum[nod]=kek[nod];
    for(auto nou:v[nod]) {
        build1(nou);
        sum[nod]+=sum[nou];
    }
}

void dfs(int nod) {
    if(sum[nod]==val)
        who[nod]=nod;
    for(auto nou:v[nod]) {
        dfs(nou);
        if(who[nou])
            who[nod]=who[nou];
    }
}

int aux[N+5],cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>t[i]>>kek[i];
        if(t[i]==0)
            root=i;
        else
            v[t[i]].push_back(i);
    }
    build1(root);
    if(sum[root]%3) {
        cout<<"-1\n";
        return 0;
    }
    val=sum[root]/3;
    dfs(root);
    for(int i=1;i<=n;i++) {
        cnt=0;
        for(auto nou:v[i]) {
            if(who[nou])
                aux[++cnt]=who[nou];
        }
        if(cnt>=2) {
            cout<<aux[1]<<" "<<aux[2]<<"\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++) {
        if(i==root)
            continue;
        if(sum[i]!=2*val)
            continue;
        int j=who[i];
        if(i!=j && j) {
            cout<<i<<" "<<j<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
/**
**/