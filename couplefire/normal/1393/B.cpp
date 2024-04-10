#include <bits/stdc++.h>
using namespace std;

int cnt[100005] = {0};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        cnt[a]++;
    }
    int num2 = 0, num4 = 0;
    for(int i = 0; i<100005; i++){
        num2 += cnt[i]/2;
        num4 += cnt[i]/4;
    }
    int q; cin >> q;
    while(q--){
        char c; int num;
        cin >> c >> num;
        if(c == '+'){
            num2 -= cnt[num]/2;
            num4 -= cnt[num]/4;
            cnt[num]++;
            num2 += cnt[num]/2;
            num4 += cnt[num]/4;
        }
        else{
            num2 -= cnt[num]/2;
            num4 -= cnt[num]/4;
            cnt[num]--;
            num2 += cnt[num]/2;
            num4 += cnt[num]/4;
        }
        if(num4 >= 1 && num2 >= 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}