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
        set<string> st;
        int n,c1=0,c2=0,c3=0,c4=0;
        vector<int> ans;
        cin >> n;
        string s[n];
        int H[n],G[n];
        for(int i=0; i<n; i++){
            cin >> s[i];
            if(s[i][0]=='1') H[i]=1;
            else H[i]=0;
            if(s[i][s[i].size()-1]=='1') G[i]=1;
            else G[i]=0;
            if(H[i] && G[i]==0) c1++;
            if(H[i] && G[i]) c3++;
            if(G[i] && H[i]==0) c2++;
            if(G[i]==0 && H[i]==0) c4++;
            st.insert(s[i]);
        }
        if(c1-1>c2){
            for(int i=0; i<n; i++){
                if(H[i] && G[i]==0){
                    string k;
                    for(int j=s[i].size()-1; j>=0; j--) k+=s[i][j];
                    int sts=st.size();
                    st.insert(k);
                    if(sts!=st.size()) c1--,c2++,ans.push_back(i+1);
                }
                if(c1-1<=c2) break;
            }
        }
        else if(c2-1>c1){
            for(int i=0; i<n; i++){
                if(G[i] && H[i]==0){
                    string k;
                    for(int j=s[i].size()-1; j>=0; j--) k+=s[i][j];
                    int sts=st.size();
                    st.insert(k);
                    if(sts!=st.size()) c1++,c2--,ans.push_back(i+1);
                }
                if(c2-1<=c1) break;
            }
        }
        if(c1==0 && c2==0 && c4>0 && c3>0) cout << -1 << '\n';
        else if(abs(c1-c2)<=1) {
            cout << ans.size() << '\n';
            for(int i : ans) cout << i << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}