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
    vector<int> p;
    for(int i=0;i<n;++i){
        if(s[i] == 'P'){
            p.push_back(i);
        }
    }
    if(p.size() == 1){
        int s1, l1, s2, r2;
        s1=s2=0;
        l1=r2=-1;
        for(int i=p[0]-1;i>=0;--i){
            if(s[i]=='*'){
                ++s1;
                l1=i;
            }
        }
        for(int i=p[0]+1;i<n;++i){
            if(s[i]=='*'){
                ++s2;
                r2=i;
            }
        }
        pair<int, int> t1(-s1, p[0]-l1), t2(-s2, r2-p[0]);
        auto t = min(t1, t2);
        cout << -t.first << " " << t.second<<"\n";
    } else {
        // can eat all;
        int cnt = 0;
        for(int i=0;i<n;++i){
            if(s[i] == '*') ++cnt;
        }
        int ans = n;
        for(int it=0;it<2;++it){
            int l=0, r=n;
            string ss;
            while(l+1<r){
                int m = l+(r-l)/2;
                bool f = false;
                int b = -1;
                ss = s;
                // clear best to left
                int cleft = 0;
                int scnt = 0;
                for(int i=n-1;i>=0;--i){
                    --cleft;
                    if(ss[i] == 'P'){
                        if(scnt == 0){
                            cleft=m+1;
                            ss[i] = '.';
                        }
                        scnt = 0;
                    } else if(ss[i] == '*'){
                        if(cleft>0){
                            ss[i] = '.';
                        } else {
                            ++scnt;
                        }
                    }
                }
                //cerr << m << " : " << ss << "\n";
                p.clear();
                for(int i=0;i<n;++i){
                    if(ss[i] == 'P'){
                        p.push_back(i);
                    }
                }
                for(int i=0;i<n;++i){
                    if(ss[i] == '*'){
                        if(b<i){
                            //grab from future
                            auto it = upper_bound(p.begin(), p.end(), i);
                            if(it == p.end()){
                                f=true;
                                break;
                            }
                            auto it2 = next(it);
                            if(it2!=p.end() && *it2-m<=i){
                                it = it2;
                            }
                            if(*it-m>i){
                                f=true;
                                break;
                            }
                            ss[*it] = '.';
                            b = *it;
                        }
                    } else if(ss[i] == 'P'){
                        b = i+m;
                    }
                }
                if(!f){
                    r=m;
                } else {
                    l=m;
                }
            }
            xmin(ans, r);
            //cerr << cnt << " " << r << "\n";
            reverse(s.begin(), s.end());
        }
        cout << cnt << " " << ans << "\n";
    }


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}