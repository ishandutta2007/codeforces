#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    map<int, int> mp;
    map<int, vector<int>> mmp;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        mp[a]++;
    }
    for(auto k : mp){
        mmp[k.second].push_back(k.first);
    }
    int ocur[n+1];
    ocur[n] = mmp[n].size();
    for(int i = n-1; i>=0; i--){
        ocur[i] = ocur[i+1]+mmp[i].size();
    }
    int cur = 0;
    int besta = 0;
    int bestb = 0;
    int bestarea = 0;
    for(int i = 1; i<=n; i++){
        cur += ocur[i];
        if(cur/i >= i && cur/i*i > bestarea){
            besta = i;
            bestb = cur/i;
            bestarea = cur/i*i;
        }
    }
    cout << bestarea << endl;
    cout << besta << " " << bestb << endl;
    vector<vector<int>> r(besta, vector<int>(bestb, 0));
    int x = 0, y = 0;
    for(int i = n; i>=1; i--){
        for(int k : mmp[i]){
            for(int j = 0; j<min(i, besta); j++){
                if(r[x][y] != 0) x = (x+1)%besta;
                if(r[x][y] == 0) r[x][y] = k;
                x = (x+1)%besta;
                y = (y+1)%bestb;
            }
        }
    }
    for(int i = 0; i<besta; i++){
        for(int j = 0; j<bestb; j++){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
}