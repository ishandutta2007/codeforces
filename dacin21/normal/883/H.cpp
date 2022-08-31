#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for(auto const&e:s){
        ++cnt[e];
    }
    int odcnt = 0;
    for(auto const&e:cnt){
        odcnt+=e.second%2;
    }
    int ans = -1;
    for(int i=1;i<=n;++i){
        if(n%i == 0){
            int o2 = (n/i%2)*i;
            if(o2>=odcnt){
                ans = i;
                break;
            }
        }
    }
    assert(ans>=1);
    cout << ans << "\n";
    int alen = n/ans;
    for(int i=0;i<ans;++i){
        string t;
        int tocnt = n/ans/2;
        for(auto &e:cnt){
            int a = min(e.second/2, tocnt);
            t.append(string(a,e.first));
            e.second-=2*a;
            tocnt-=a;
        }
        cout << t;
        assert(tocnt==0);
        if(n/ans%2){
            auto *cand = &*cnt.begin();
            for(auto &e:cnt){
                if(e.second) cand=&e;
            }
            for(auto &e:cnt){
                if(e.second%2) cand=&e;
            }
            assert(cand->second);
            --cand->second;
            cout << cand->first;
        }

        reverse(t.begin(), t.end());
        cout << t << " ";
    }
    cout << "\n";



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}