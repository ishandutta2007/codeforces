#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005
#define SIZ 495

map<array<int, 5>, int> mp;
vector<int> adj[MAXN];
array<int, 5> curstate;
vector<array<int, 5>> states;
vector<int> ans(SIZ*SIZ, -1);
int cnt[SIZ*SIZ];
int lol[SIZ*SIZ];
// array<int, 5> c1 = {7, 1, 0, 0, 0}, c2 = {8, 0, 0, 0, 0};

void genStates(int num, int tot){
    if(num == 5){
        if(tot == 0) states.push_back(curstate), mp[curstate] = states.size()-1;
        return;
    }
    for(int i = 0; i<=tot; i++){
        curstate[num] = i;
        genStates(num+1, tot-i);
    }
}

int getInd(int i, int j){return SIZ*i+j;}

void buildGraph(){
    for(int i = 0; i<SIZ; i++){
        for(int j = 0; j<SIZ; j++){
            array<int, 5> s1 = states[i], s2 = states[j];
            for(int a = 1; a<5; a++){
                if(s1[a] == 0) continue;
                for(int b = 1; b<5; b++){
                    if(s2[b] == 0) continue;
                    s1[a]--;
                    s1[(a+b)%5]++;
                    int newid = mp[s1];
                    // if(s2 == c1 && s1 == c2) cout << "YES" << endl;
                    adj[getInd(j, newid)].push_back(getInd(i, j));
                    lol[getInd(i, j)]++;
                    s1[a]++;
                    s1[(a+b)%5]--;
                }
            }
        }
    }
}

void calc(){
    queue<pair<int, int>> q;
    for(int i = 0; i<SIZ; i++){
        if(states[i][0] != 8) continue;
        for(int j = 0; j<SIZ; j++){
            ans[getInd(i, j)] = 1;
            ans[getInd(j, i)] = 0;
            q.push({i, j});
            q.push({j, i});
        }
    }
    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();
        int ind = getInd(a, b);
        if(ans[ind] == 0){
            for(auto v : adj[ind]){
                if(ans[v] == -1){
                    ans[v] = 1;
                    q.push({v/SIZ, v%SIZ});
                }
            }
        }
        else{
            for(auto v : adj[ind]){
                cnt[v]++;
                if(cnt[v] == lol[v]){
                    ans[v] = 0;
                    q.push({v/SIZ, v%SIZ});
                }
            }
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    genStates(0, 8);
    buildGraph();
    calc();
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        array<int, 5> s1, s2;
        for(int i = 0; i<5; i++) s1[i] = 0, s2[i] = 0;
        for(int i = 0; i<8; i++){
            int a; cin >> a;
            s1[a]++;
        }
        for(int i = 0; i<8; i++){
            int a; cin >> a;
            s2[a]++;
        }
        if(t == 1) swap(s1, s2);
        int num = ans[getInd(mp[s1], mp[s2])];
        if(num == 0) cout << ((t == 1) ? "Alice" : "Bob") << endl;
        else if(num == 1) cout << ((t == 1) ? "Bob" : "Alice") << endl;
        else cout << "Deal" << endl;
    }
    // int i1 = mp[c1], i2 = mp[c2]; int ind = getInd(i1, i2);
    // cout << i1 << " " << i2 << endl;
    // for(auto v : adj[ind]){
    //     int a = v/SIZ, b = v%SIZ;
    //     for(int i = 0; i<5; i++) cout << states[a][i] << " ";
    //     cout << endl;
    //     for(int i = 0; i<5; i++) cout << states[b][i] << " ";
    //     cout << endl << endl;
    // }
}