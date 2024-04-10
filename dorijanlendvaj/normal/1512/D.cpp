#include<bits/stdc++.h>
#define int long long
#define db(x) (cerr << #x << ": " << (x) << '\n')
const int INF = 1000000007;
using namespace std;

int32_t main(){  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n += 2;
        vector<int> a(n);
        multiset<int> s;
        int sum = 0;
        for(int i{}; i < n; ++i){
            cin>>a[i];
            sum += a[i];
            s.insert(a[i]);
        }
        sort(a.begin(), a.end());
        if(s.find(sum - (2 * a[n - 1])) != s.end() && (sum != 3 * a[n - 1] || s.count(a[n - 1]) > 1)){
            s.erase(s.find(sum - (2 * a[n - 1])));
            s.erase(s.find(a[n - 1]));
            for(auto x: s)
                cout<<x<<" ";
        }
        else if(s.find(sum - (2 * a[n - 2])) != s.end() && (sum != 3 * a[n - 2] || s.count(a[n - 2]) > 1)){
                s.erase(s.find(sum - (2 * a[n - 2])));
                s.erase(s.find(a[n - 2]));
                for(auto x: s)
                    cout<<x<<" ";
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}