#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> blocks;
        char cur = s[0];
        int len = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == cur){
                len++;
            }
            else{
                blocks.push_back(len);
                cur = s[i];
                len = 1;
            }
        }
        blocks.push_back(len);
        // for(auto i : blocks) cout << i << " ";
        // cout << endl;
        int cnt = 0;
        int index = 0;
        for(int i = 0; i<blocks.size(); i++){
            index = max(index, i);
            while(index < blocks.size() && blocks[index] == 1) index++;
            if(index >= blocks.size()){
                blocks.pop_back();
            }
            else blocks[index]--;
            cnt++;
        }
        cout << cnt << endl;
    }
}