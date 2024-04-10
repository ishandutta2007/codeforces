#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX] , ans[MAX] , cnt[MAX];
vector<int> v[MAX];
priority_queue<PII , vector<PII> , greater<PII> > pq;
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1){
        cin >> x[i];
        v[x[i]].pb(i);
    }

    REP(i , 1 , n + 1){
        if(v[i].size() > 1){
            pq.push(mp(v[i][0] , i));
        }
    }
    int fk = 0;
    REP(i , 1 , n + 1){
        if(v[i].size()){
            ans[v[i][cnt[i] ++]] = i;
            if(cnt[i] < v[i].size()){
                pq.push(mp(v[i][cnt[i]] , i));
            }
        }
        else if(cnt[i] == 0){
            fk ++;
            while(pq.size()){
                PII tmp = pq.top(); pq.pop();
                if(ans[tmp.A] != 0) continue;
                else {
                    ans[tmp.A] = i;
                    cnt[tmp.B] ++;
                    if(tmp.B > i){
                        if(cnt[tmp.B] + 1 < v[tmp.B].size())
                            pq.push(mp(v[tmp.B][cnt[tmp.B]] , tmp.B));
                    }
                    else {
                        if(cnt[tmp.B] < v[tmp.B].size()){
                            pq.push(mp(v[tmp.B][cnt[tmp.B]] , tmp.B));
                        }
                    }
                    break;
                }
            }
        }
        // cout << "cnt = " ;REP(i , 1 , n + 1) cout << cnt[i] << " " ; cout << endl;
    }
    cout << fk << endl;
    REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}