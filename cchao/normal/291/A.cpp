#include <iostream>
#include <map>
using namespace std;
map<int,int> m;
int main(){
    int n, a, ans=0;
    cin >> n;
    while(n--){
        cin >> a;
        if(a==0) continue;
        m[a]++;
        if(m[a]==2) ++ans;
        if(m[a] > 2){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}