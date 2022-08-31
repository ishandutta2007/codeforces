#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll inf = 1e18;
int main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTTT; cin >> TTTT;
    while(TTTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n;
    cin >> n;
    vector<string> ss(n);
    vector<int> occ(2*1000000+20, -1);

    for(int i=0;i<n;++i){
        cin >> ss[i];
        int k; cin >> k;
        while(k--){
            int l; cin >> l;
            if(occ[l] == -1 || ss[i].size()>ss[occ[l]].size()){
                occ[l] = i;
            }
        }
    }
    string s; s.reserve(occ.size());
    int j = -1, last=-1;
    for(int i=1;i<(int)occ.size();++i){
        if(j>=0 && i-j >= ss[occ[j]].size()) j=-1;
        if(occ[i]>=0){
            if(j == -1 || ss[occ[i]].size() + (i-j) >= ss[occ[j]].size()){
                j = i;
            }
        }
        if(j == -1){
            s.push_back('a');
            continue;
        }
        s.push_back(ss[occ[j]][i-j]);
        last = i;
    }
    s.erase(s.begin()+last, s.end());
    cout << s << "\n";


    #ifdef LOCAL_RUN
    cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}