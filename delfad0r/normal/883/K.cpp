#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    out << "[";
    for (int x : vec) out << x << ", ";
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define dbg_var(x) clog << #x << ": " << x << endl;
#endif

int main() {
    int n;
    cin >> n;
    vector<int> s(n+1), g(n+1), v(n+1);
    for(int i=1; i<=n; i++) cin >> s[i] >> g[i];
    for(int i=1; i<=n; i++) v[i] = s[i] + g[i];
    for(int i=2; i<=n; i++){
        if(v[i] > v[i-1]+1) v[i] = v[i-1]+1;
    }
    
    
    long long ans = 0;
    //~ for(int i=1; i<=n; i++){
        //~ if(v[i] < s[i]){cout << -1 << '\n'; return 0;}
        //~ ans += v[i]-s[i];
    //~ }
    //~ cout << ans << '\n';
    //~ for(int i=1; i<=n; i++) cout << v[i] << ' ';
    //~ cout << '\n';

    
    int val = 3000000;
    for(int i=n; i>0; i--){
        int myval = v[i]+i;
        if(myval < val){
            //~ cerr << i << " is low" << endl;
            val = myval;
        }else{
            //~ cerr << i << ' ' << myval << ' ' << val << endl;
            v[i]-=myval-val;
        }
    }
    
    ans = 0;
    for(int i=1; i<=n; i++){
        if(v[i] < s[i]){cout << -1 << '\n'; return 0;}
        ans += v[i]-s[i];
    }
    
    cout << ans << '\n';
    for(int i=1; i<=n; i++) cout << v[i] << ' ';
    cout << '\n';
    return 0;
}