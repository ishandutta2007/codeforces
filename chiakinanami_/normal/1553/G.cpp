#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct disjointSet{
    int par[150005];

    void init(int n){
        for(int i=0; i<=n; i++) par[i] = i;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        x = find(x), y = find(y);
        par[x] = y;
    }
} dsu;

int n, q;
int arr[150002];
vector<int> factVec[1000004];
int qa[300002], qb[300002];
int ans[300002];
int pnt[1000004];

map<int, int> link[150002];

int main(){
    scanf("%d %d", &n, &q);
    dsu.init(n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        int tmp = arr[i];
        for(int j=2; j*j<=tmp; j++){
            if(tmp%j) continue;
            factVec[j].push_back(i);
            while(tmp%j==0){
                tmp /= j;
            }
        }
        if(tmp > 1) factVec[tmp].push_back(i);
    }
    for(int i=2; i<=1000001; i++){
        if(factVec[i].empty()) continue;
        pnt[i] = factVec[i][0];
        for(int j=0; j<(int)factVec[i].size()-1; j++){
            dsu.merge(factVec[i][j], factVec[i][j+1]);
        }
    }
    for(int i=2; i<=1000001; i++){
        if(!pnt[i]) continue;
        pnt[i] = dsu.find(pnt[i]);
    }

    for(int i=1; i<=n; i++){
        int tmp = arr[i] + 1;
        int par = dsu.find(i);
        vector<int> newVec;
        for(int j=2; j*j<=tmp; j++){
            if(tmp%j) continue;
            while(tmp%j==0) tmp/=j;
            if(!pnt[j]) continue;
            newVec.push_back(pnt[j]);
            link[par][pnt[j]] = 1;
        }
        if(pnt[tmp]) link[par][pnt[tmp]] = 1, newVec.push_back(pnt[tmp]);
        for(auto x: newVec) for(auto y: newVec) link[x][y] = 1;
    }

    for(int i=1; i<=q; i++){
        scanf("%d %d", &qa[i], &qb[i]);
        qa[i] = dsu.find(qa[i]), qb[i] = dsu.find(qb[i]);
        if(qa[i]==qb[i]) continue;
        if(link[qa[i]][qb[i]] || link[qb[i]][qa[i]]){
            ans[i] = 1;
            continue;
        }
        ans[i] = 2;
    }

    for(int i=1; i<=q; i++){
        printf("%d\n", ans[i]);
    }
}