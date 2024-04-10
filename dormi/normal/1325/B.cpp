#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        set<int> dis;
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
            dis.insert(arr[i]);
        }
        printf("%d\n",sz(dis));
    }
    return 0;
}