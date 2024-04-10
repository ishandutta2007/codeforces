#include <bits/stdc++.h>
using namespace std;
#define MAXN 205

vector<pair<int, int>> cur;
vector<int> tmpcur;
int n;
int arr[6*MAXN];
vector<pair<int, array<int, 3>>> nodes;
vector<int> adj[2*MAXN];
int par[2*MAXN];
int isRoot[2*MAXN];
int dead[2*MAXN];
int cnt[2*MAXN];

void init(){
    fill(isRoot, isRoot+2*MAXN, 1);
    fill(par, par+2*MAXN, -1);
    for(int i = 0; i<6*n; i++){
        cur.push_back({arr[i], i});
        if(cur.size() >= 3){
            if(cur[cur.size()-1].first == cur[cur.size()-2].first && cur[cur.size()-2].first == cur[cur.size()-3].first &&
               (cur[cur.size()-1].second-2)%3 == (cur[cur.size()-2].second-1)%3 && (cur[cur.size()-2].second-1)%3 == cur[cur.size()-3].second%3
            ){
                nodes.push_back({arr[i], {cur[cur.size()-3].second, cur[cur.size()-2].second, cur[cur.size()-1].second}});
                while(!tmpcur.empty() && nodes[tmpcur.back()].second[0] >= cur[cur.size()-3].second){
                    adj[nodes.size()-1].push_back(tmpcur.back());
                    cnt[nodes.size()-1]++;
                    par[tmpcur.back()] = nodes.size()-1;
                    isRoot[tmpcur.back()] = 0;
                    tmpcur.pop_back();
                }
                tmpcur.push_back(nodes.size()-1);
                cur.pop_back(); cur.pop_back(); cur.pop_back();
            }
        }
    }
}

void solve(){
    for(int i = 0; i<2*n; i++){
        if(i%2 == 0){
            for(int j = 0; j<2*n; j++){
                if(dead[j]) continue;
                if(cnt[j] == 0 && nodes[j].first == 1){
                    for(int k = 0; k<3; k++) cout << nodes[j].second[k]+1 << " ";
                    cout << endl;
                    dead[j] = 1;
                    if(par[j] != -1) cnt[par[j]]--;
                    break;
                }
            }
        }
        else{
            bool work = false;
            for(int j = 0; j<2*n; j++){
                if(dead[j]) continue;
                if(cnt[j] == 0 && nodes[j].first == 0 && par[j] != -1){
                    for(int k = 0; k<3; k++) cout << nodes[j].second[k]+1 << " ";
                    cout << endl;
                    dead[j] = 1;
                    cnt[par[j]]--;
                    work = 1;
                    break;
                }
            }
            if(!work){
                for(int j = 0; j<2*n; j++){
                    if(dead[j]) continue;
                    if(cnt[j] == 0 && nodes[j].first == 0){
                        for(int k = 0; k<3; k++) cout << nodes[j].second[k]+1 << " ";
                        cout << endl;
                        dead[j] = 1;
                        break;
                    }
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
    cin >> n;
    for(int i = 0; i<3*n; i++){
        int a; cin >> a; --a;
        arr[a] = 1;
    }
    init();
    solve();
}