#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

int n;
vi a(4);
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--){
    	for(int i = 0; i < 4; i++){
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end());
    	cout << a[0] * a[2] << endl;
    }
}