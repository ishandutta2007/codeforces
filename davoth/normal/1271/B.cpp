#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int main() {
    fast_io;
    int n;
    cin >> n;
    bool a[n],b[n];
    vector<int> ans1,ans2;
    for(int i=0; i<n; i++){
        char s;
        cin >> s;
        a[i] = s == 'B';
        b[i]=a[i];
    }
    if(n==1) return cout<<0,0;
    for(int i=0; i<n-1; i++){
        if(a[i]){
            a[i]=!a[i];
            a[i+1]=!a[i+1];
            ans1.push_back(i+1);
        }
        if(!b[i]){
            b[i]=!b[i];
            b[i+1]=!b[i+1];
            ans2.push_back(i+1);
        }
    }
    if(!a[n-1]){
        cout << ans1.size() << '\n';
        for(int i : ans1) cout << i << ' ';
        return 0;
    }
    if(b[n-1]){
        cout << ans2.size() << '\n';
        for(int i : ans2) cout << i << ' ';
        return 0;
    }
    cout << -1;
    return 0;
}