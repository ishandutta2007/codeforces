#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int arr[n];
    string s; cin >> s;
    for(int i = 0; i<n; i++) arr[i] = s[i];
    int result[n];
    int cur = 0;
    set<pair<int, int>> st;
    for(int i = 0; i<n; i++){
        auto it = st.upper_bound({arr[i], n+1});
        if(it == st.begin()){
            st.insert({arr[i], ++cur});
            result[i] = cur;
        }
        else{
            --it;
            int t = (*it).second;
            st.erase(it);
            st.insert({arr[i], t});
            result[i] = t;
        }
    }
    cout << st.size() << endl;
    for(int i = 0; i<n; i++) cout << result[i] << " ";
    cout << endl;
}