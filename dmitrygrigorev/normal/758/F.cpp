#include <bits/stdc++.h>
#define int long long
using namespace std;
int pw(int a, int b){
    if (b==0) return 1;
    if (b%2==1){
        int res = pw(a, b/2);
        return a*res*res;
    }
    int res = pw(a, b/2);
    return res*res;
}
signed main(){
    int n, l, r;
    cin >> n >> l >> r;
    if (n==1){
        cout << r-l+1 << endl;
        return 0;
    }
    if (n==2){
        cout << (r-l+1)*(r-l) << endl;
        return 0;
    }
    if (n > 30){
        cout << 0 << endl;
        return 0;
    }
    vector<int> st;
    int now = 1;
    while (true){
        int res = pw(now, n-1);
        if (res > r) break;
        st.push_back(res);
        now++;
    }
    int ans = 0;
    for (int i=0; i < st.size(); i++){
        for (int j=i+1; j < st.size(); j++){
            if (__gcd(i+1, j+1) != 1) continue;
            int y = st[j];
            int x = st[i];
            int A = l/x;
            if (l%x!=0) A++;
            int B = r/y;
            if (B >= A){
                ans+=B-A+1;
            }
        }
    }
    cout << ans*2 << endl;
}