#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int t;
int main() {
    fast_io;
    cin >> t;
    while(t--){
        set<int> st;
        int n,ans=0;
        cin >> n;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            st.insert(x);
        }
        while(!st.empty()){
            int x=*st.rbegin();
            if(x&1) st.erase(x);
            else{
                st.insert(x/2);
                st.erase(x);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}