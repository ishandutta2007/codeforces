#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int get(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    cout << endl;
    return ans;
}
void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    
    int size = (1LL << n);
    for(int i = 1; i <= size; i++) {
        arr.push_back(i);
    }
    
    for (int i = 1; i < n; i++){
        vector<int> newArr;
        
        size /= 2;
        int curr = 0;
        for(int i = 0; i < size / 2; i++) {
            int out = get(arr[curr], arr[curr + 2]);
            
            if(out == 0) {
                newArr.push_back(arr[curr + 1]);
                newArr.push_back(arr[curr + 3]);
            } else if(out == 1) {
                newArr.push_back(arr[curr]);
                newArr.push_back(arr[curr + 3]);
            } else {
                newArr.push_back(arr[curr + 2]);
                newArr.push_back(arr[curr + 1]);
            }
            curr += 4;
        }
        arr = newArr;
    }
    int ans = get(arr[0], arr[1]);
    cout << "! " << (ans == 1 ? arr[0] : arr[1]) << endl;
} 
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}