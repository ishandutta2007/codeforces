#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        --arr[i];
    }
    set<int, greater<int>> st;
    for(int i = 0; i<n; i++) st.insert(i);
    vector<pair<int, int>> edges;
    int root = arr[0];
    st.erase(root);
    int cur = 1;
    set<int> visited;
    visited.insert(root);
    int prev = root;
    while(cur < n-1 && st.size()){
        int curmax = *st.begin();
        while(cur < n-1 && !visited.count(arr[cur]) && arr[cur] != curmax){
            edges.push_back({prev, arr[cur]});
            visited.insert(arr[cur]);
            prev = arr[cur];
            st.erase(arr[cur++]);
        }
        edges.push_back({prev, curmax});
        st.erase(curmax);
        visited.insert(curmax);
        if(cur < n-1){
            prev = arr[cur];
        }
        cur++;
    }
    if(cur < n) edges.push_back({*st.begin(), prev});
    cout << root+1 << endl;
    for(auto i : edges){
        cout << i.first+1 << " " << i.second+1 << endl;
    }
}