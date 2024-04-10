#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int arr[n];
        set<int> stuff;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            --arr[i];
            stuff.insert(arr[i]);
        }
        vector<int> v;
        for(auto i : stuff) v.push_back(i);
        set<int> pos[n];
        for(int i = 0; i<n; i++){
            pos[arr[i]].insert(i);
        }
        int curbest = 0;
        int j = 0;
        for(int i = 0; i<v.size(); i++){
            j = max(j, i);
            while(j < v.size()-1 && (*pos[v[j+1]].begin()) > (*pos[v[j]].rbegin())) j++;
            curbest = max(curbest, j-i+1);
        }
        cout << v.size()-curbest << endl;
    }
}