#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    int sum = 0;
    for(int i = 0; i<n; i++) sum += arr[i];
    vector<pair<int, int>> blocks;
    int res[n][n+1];
    blocks.push_back({0, n});
    for(int i = 0; i<n; i++){
        while(blocks.back().second == blocks.back().first) blocks.pop_back();
        // for(auto k : blocks){
        //     cout << "{" << k.first << " " << k.second << "}" << " ";
        // }
        // cout << endl;
        int num1 = arr[i];
        int num0 = n+1-num1;
        int siz = blocks.size()-1;
        int nn0 = min(num0, blocks[siz].second-blocks[siz].first);
        int nn1 = blocks[siz].second-blocks[siz].first+1-nn0;
        num0 -= nn0;
        num1 -= nn1;
        int left = blocks[siz].first, right = blocks[siz].second;
        int swi = left+nn0;
        for(int j = blocks[siz].first; nn0 > 0 || nn1 > 0; j++){
            if(nn0 > 0){
                res[i][j] = 0;
                nn0--;
            }
            else{
                res[i][j] = 1;
                nn1--;
            }
        }
        blocks.pop_back();
        blocks.push_back({left, swi-1});
        blocks.push_back({swi, right});
        for(int j = 0; j<=n; j++){
            if(j >= left && j <= right) continue;
            if(num1 > 0){
                res[i][j] = 1;
                num1--;
            }
            else{
                res[i][j] = 0;
                num0--;
            }
        }
    }
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<=n; j++){
    //         cout << res[i][j];
    //     }
    //     cout << endl;
    // }
    cout << n+1 << endl;
    for(int j = 0; j<=n; j++){
        for(int i = 0; i<n; i++){
            cout << res[i][j];
        }
        cout << endl;
    }
}