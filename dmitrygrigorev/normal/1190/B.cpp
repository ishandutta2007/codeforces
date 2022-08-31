#include<bits/stdc++.h>
#define int long long
using namespace std;
string F = "sjfnb", S="cslnb";
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (v.back() == 0){
        cout << S << endl;
        return 0;
    }
    if (v.size() == 1){
        if (v[0] % 2 != 0) cout << F << endl;
        else cout << S << endl;
        return 0;
    }
    if (v[1] == 0){
        cout << S << endl;
        return 0;
    }
    int number = 0, index = -1;
    for (int i=1; i < n; i++){
        if (v[i] == v[i-1]){
            number++;
            index = i;
        }
    }
    if (number >= 2){
        cout << S << endl;
        return 0;
    }
    if (number == 1){
        v[index]--;
        sort(v.begin(), v.end());
        int tumber = 0;
        for (int i=1; i < n; i++){
            if (v[i] == v[i-1]){
                tumber++;
            }
        }
        if (tumber != 0){
            cout << S << endl;
            return 0;
        }
        swap(F, S);
    }
    int sum = 0;
    for (int i=0; i < n; i++) sum += v[i];
    for (int i=0; i < n; i++) sum -= i;
    if (sum % 2 == 0) cout << S << endl;
    else cout << F << endl;
    return 0;
}