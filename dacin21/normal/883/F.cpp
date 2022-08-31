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
    set<string> m;
    for(int i=0;i<n;++i){
        cin >> s;
        string ss;
        for(auto const&e:s){
            ss.push_back(e);
            if(ss.rbegin()[0] == 'u'){
                ss.back() = 'o';
                ss.push_back('o');
            }
            while(ss.size()>=2){
                if(ss.rbegin()[0] == 'h' && ss.rbegin()[1] == 'k'){
                    ss.pop_back();
                    ss.back() = 'h';
                } else break;
            }
        }
        m.insert(ss);
    }
    /*for(auto const&e:m){
        cerr << e << "\n";
    }*/
    cout << m.size() << '\n';


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}