#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 209000
#define INF 1000000000000LL

int n , k;
int ok;
int x[MAX] , use[MAX];
vector<PII> v[MAX];
int solve(){
    REP(i , 0 , n){
        int now = i;
        while(now < n && use[now] == 0){
            use[now] = 1;
            v[i].pb(mp(x[now] , now));
            now += k;
        }
    }
    REP(i , 0 , n){
        if(v[i].size() == 0) continue;
        // DBGG("cout " ," hrere");

        vector<PII> num;

        num.pb(mp(-INF , i - k));
        for(auto now : v[i])
            if(now.A != INF) num.pb(now);
        int tmp = v[i].back().B;
        num.pb(mp(INF , tmp + k));

        // for(auto now : num) cout << now.A << " " ;cout << endl; 

        REP(j , 1 , num.size()){
            int frval = num[j - 1].A , frpos = num[j - 1].B;
            int baval = num[j].A , bapos = num[j].B;
            // DB4(frpos , frval , bapos , baval);
            int siz = (bapos - frpos) / k - 1 , ooo = 0;
            if(frval < 0 && baval > 0){
                // DBGG("siz = " , siz);
                if(siz % 2 == 1){
                    if(frval < (siz / 2) * -1 && baval > siz / 2){
                        // DBGG("hree" , "0");
                        ooo = 1;
                        int ppos = frpos + k , cnt = (siz / 2) * -1;
                        while(ppos < bapos) x[ppos] = cnt ++ , ppos += k;
                        // DBGG("hree" , "1");
                    }
                }
                else {
                    if(frval < (siz / 2 - 1) * -1 && baval > siz / 2){
                        ooo = 1;
                        int ppos = frpos + k , cnt = (siz / 2 - 1) * -1;
                        while(ppos < bapos) x[ppos] = cnt ++ , ppos += k;
                    }
                }

            }
            if(ooo == 1) continue;
            int pos = frpos + k , val = frval + 1;
            while(pos < bapos){
                if(abs(val) < abs(x[pos])) x[pos] = val;
                val ++ , pos += k;
            }
            // DBGG("val = " , val);
            if(val > baval) ok = 0;

            pos = bapos - k , val = baval - 1;
            while(pos > frpos){
                if(abs(val) < abs(x[pos])) x[pos] = val;
                val -- , pos -= k;
            }
            if(val < frval) ok = 0;
        }

    }
        
    return 0;
}
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 0 , n){
        string s;
        cin >> s;
        if(s[0] == '?') x[i] = INF;
        else {
            stringstream ss(s);
            ss >> x[i];
        }
    }
    ok = 1; 
    solve();
    REP(i , 0 , n) if(x[i] == INF) ok = 0;
    if(ok == 0) cout << "Incorrect sequence" << endl;
    else {
        // DBGG("ans = " , "here");
        REP(i , 0 , n) cout << x[i] << " ";
        cout << endl;
    }
    return 0;
}

        // if(num.size() == 0 && 0){
        //     int siz = num.size();
        //     if(siz & 1){
        //         REP(j , siz / 2 , siz) x[v[i][j].B] = j;
        //         int cnt = -1;
        //         RREP(j , siz / 2 - 1 , 0) x[v[i][j].B] = cnt--;
        //     }
        //     else {
        //         int cnt = -1;
        //         REP(j , siz / 2 , siz) x[v[i][j].B] = cnt ++;
        //         cnt = -1;
        //         RREP(j , siz / 2 - 1 , 0) x[v[i][j].B] = cnt --;
        //     }
        // }
        // else {

            // REP(j , 0 , v[i].size()){
            //     cout << v[i][j].A << " " ;
            // } cout << endl;
    //         REP(j , 0 , num.size()){
    //             int ll , rr , lsiz , rsiz;
    //             if(j == 0) ll = -INF , lsiz = i;
    //             else ll = num[i][j - 1].A , lsiz = num[i][j - 1].B;

    //             if(j + 1 == v[i].size()) rr = INF;
    //             else rr = num[i][j + 1].A;
    //             if(ll < 0 && rr > 0){
    //                 int len = (rr - ll) / k + 1;
    //                 if(len & 1){
    //                     int pp = len / 2;
    //                     if(ll < )
    //                 }
    //             }
    //         }

    //         REP(j , 0 , v[i].size()){
    //             if(v[i][j].A == INF) continue;

    //             int id = v[i][j].B , cnt = -1;
    //             RREP(k , j - 1 , 0){
    //                 if(v[i][k].A != INF){
    //                     if(x[v[i][k].B] > x[id] - cnt) return -1;
    //                     else break;
    //                 }
    //                 if(abs(x[v[i][k].B]) > abs(x[id] + cnt))
    //                     x[v[i][k].B] = x[id] + cnt;
    //                 cnt --;
    //             }
    //             cnt = 1;
    //             REP(k , j + 1 , v[i].size()){
    //                 if(v[i][k].A != INF){
    //                     if(x[v[i][k].B] < x[id] + cnt) return -1;
    //                     else break;
    //                 }
    //                 // DBGG("why = " , x[id] + cnt);
    //                 if(abs(x[id] + cnt) < abs(x[v[i][k].B]))
    //                     x[v[i][k].B] = x[id] + cnt;
    //                 cnt ++;
    //             }
    //         }
    //     }
    // }