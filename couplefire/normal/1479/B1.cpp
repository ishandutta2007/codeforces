#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> blocks;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        if(blocks.empty() || blocks.back()[0] != a){
            blocks.push_back({}); blocks.back().push_back(a);
        }
        else blocks.back().push_back(a);
    }
    int ans = 0;
    vector<int> bruh;
    for(int i = 0; i<blocks.size(); i++){
        if(blocks[i].size() >= 2) ans += 2, bruh.push_back(i);
        else ans += 1;
    }
    for(int i = 0; i<(int)bruh.size()-1; i++){
        if(blocks[bruh[i]][0] != blocks[bruh[i+1]][0]) continue;
        ans--;
        for(int j = bruh[i]+1; j<bruh[i+1]; j++){
            if(blocks[j-1][0] != blocks[j+1][0] && blocks[j][0] != blocks[bruh[i]][0]){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}