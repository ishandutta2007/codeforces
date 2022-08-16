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

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &e:a) cin >> e;
    ll ret = 0;
    priority_queue<pair<ll, int> > pq;
    ll sum = 0;
    vector<int> out(n);
    for(int i=0;i<n+k;++i){
        if(i<n){
            pq.push({a[i], i});
            sum+=a[i];
        }
        if(i>=k){
            sum-=pq.top().first;
            out[pq.top().second] = i+1;
            pq.pop();
        }
        ret+=sum;
    }
    cout << ret << "\n";
    copy(out.begin(), out.end(), ostream_iterator<int>(cout, " "));



    #ifdef LOCAL_RUN
        cout << "\n";
    }
    #endif // LOCAL_RUN
    return 0;
}