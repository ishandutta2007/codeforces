#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Ans{int l; int r; int d;};
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > s(n);
    vector<int> t(n);
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        s[i] = {x, i};
    }
    for (int i=0; i < n; i++) cin >> t[i];
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i=0;i<n;i++) s[i].first -= t[i];
    for (int i=0;i<n;i++) s[i].first *= -1;
    vector<pair<int, int> > pl;
    vector<Ans> answer;
    for (int i=0; i < n; i++){
        if (s[i].first > 0){
            pl.push_back(s[i]);
        }
        else{
            int need = -s[i].first;
            while (need > 0 && pl.size() > 0){
                if (pl.back().first > need){
                    answer.push_back({pl.back().second, s[i].second, need});
                    pl.back().first -= need;
                    need=0;
                    break;
                }
                else{
                    answer.push_back({pl.back().second, s[i].second, pl.back().first});
                    need -= pl.back().first;
                    pl.pop_back();
                }
            }
            if (need > 0){
                cout << "NO";
                return 0;
            }
        }
    }
    if (pl.size()){
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    cout << answer.size() << "\n";
    for (int i=0;i<answer.size(); i++) cout << answer[i].l+1 << " " << answer[i].r+1 << " " << answer[i].d << "\n";

}