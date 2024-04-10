#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n);
    int odd = 0;
    for(int i = 0; i<n; i++)
        cin >> arr[i], odd += ((arr[i]+1000)%2==1);
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if((arr[i]+1000)%2 == 0){
            cout << arr[i]/2 << '\n';
        } else{
            if(cnt < odd/2) cout << min(arr[i], 0)+(max(arr[i], 0)-min(arr[i], 0))/2 << '\n';
            else cout << min(arr[i], 0)+(max(arr[i], 0)-min(arr[i], 0))/2+1  << '\n';
            cnt++;
        }
    }
}