#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for(int noob=0; noob<t; noob++){
        int n,k;
        cin >> n >> k;
        int a[n],x,y,z;
        for(int i=0; i<n; i++) cin >> a[i];
        reverse(a,a+n);
        x=0;
        vector<int> ans;
        ans.clear();
        for(int i=0; i<n; i++) if(a[i]%2) ans.push_back(n-i);
        if(ans.empty()){
            cout << "NO\n";
            continue;
        }
        if((ans.size()-k)%2||ans.size()<k){
            cout << "NO\n";
            continue;
        }
        ans[0]=n;
        while(ans.size()>k) ans.pop_back();
        reverse(ans.begin(),ans.end());
        cout << "YES\n";
        for(int i=0; i<k; i++) cout << ans[i] << ' ';
        cout << "\n";
    }
}