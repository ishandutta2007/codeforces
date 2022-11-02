/*input
5
set economicsessay 1
remove economicsessay
undo 1
undo 1
query economicsessay
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100100
#define INF 1000000008
#define mid (l + r >> 1)
const int Treesize = MAX * 80;

int idxr[MAX] , idx[Treesize] , idxls[Treesize] , idxrs[Treesize] , idxpos = 2;
int valr[MAX] , val[Treesize] , valls[Treesize] , valrs[Treesize] , valpos = 2;

int updateidx(int dot , int l , int r , int k , int v){
    int now = idxpos ++;
    idx[now] = idx[dot];
    idxls[now] = idxls[dot];
    idxrs[now] = idxrs[dot];
    if(l == r) return idx[now] = v , now;
    else {
        if(k <= mid + 0) idxls[now] = updateidx(idxls[now] , l , mid + 0 , k , v);
        if(mid + 1 <= k) idxrs[now] = updateidx(idxrs[now] , mid + 1 , r , k , v);
        return now;
    }
}
int updateval(int dot , int l , int r , int k , int v){
    int now = valpos ++;
    val[now] = val[dot];
    valls[now] = valls[dot];
    valrs[now] = valrs[dot];
    if(l == r) return val[now] += v , now;
    else{
        if(k <= mid + 0) valls[now] = updateval(valls[now] , l , mid + 0 , k , v);
        if(mid + 1 <= k) valrs[now] = updateval(valrs[now] , mid + 1 , r , k , v);
        val[now] = val[valls[now]] + val[valrs[now]];
        return now;
    }
}
int queryidx(int now , int l , int r , int k){
    if(l == r) return idx[now];
    else if(k <= mid + 0) return queryidx(idxls[now] , l , mid + 0 , k);
    else if(mid + 1 <= k) return queryidx(idxrs[now] , mid + 1 , r , k);
}
int queryval(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return val[now];
    else if(qr <= mid + 0) return queryval(valls[now] , l , mid + 0 , ql , qr);
    else if(mid + 1 <= ql) return queryval(valrs[now] , mid + 1 , r , ql , qr);
    return queryval(valls[now] , l , mid + 0 , ql , qr) + queryval(valrs[now] , mid + 1 , r , ql , qr);
}

map<string , int> trs;
int TRS(string s){
    if(trs.find(s) == trs.end()) trs[s] = trs.size();// , DB4("str " , s , " = " , trs[s]);
    return trs[s];
}
void ADD(int root , int who , int vvv){
    int tmp = queryidx(idxr[root] , 1 , MAX , who);
    if(tmp != 0) valr[root] = updateval(valr[root] , 1 , INF , tmp , -1);
    // DB4(who , vvv , tmp , "");
    idxr[root] = updateidx(idxr[root] , 1 , MAX , who , vvv);
    valr[root] = updateval(valr[root] , 1 , INF , vvv , 1);
    // DB4("wnt = " , vvv , who , queryidx(idxr[root] , 1 , MAX , who));
}
void STR(int root , int who){
    int tmp = queryidx(idxr[root] , 1 , MAX , who);
    // DB4("hree" , tmp , "who = " , who);
    if(tmp != 0){
    	// cout << "here" << endl;
        idxr[root] = updateidx(idxr[root] , 1 , MAX , who , 0);
        valr[root] = updateval(valr[root] , 1 , INF , tmp , -1);
    }
}
int n;
int32_t main(){
    IOS;
    cin >> n;
    idxr[0] = valr[0] = 1;
    REP(i , 1 , n + 1){
        string type , s;
        int xx;
        cin >> type;

        idxr[i] = idxr[i - 1] , valr[i] = valr[i - 1];
        if(type == "set"){
            cin >> s >> xx;
            ADD(i , TRS(s) , xx);
        }
        if(type == "remove"){
            cin >> s;
            STR(i , TRS(s));
        }
        if(type == "query"){
            cin >> s;
            int tmp = queryidx(idxr[i] , 1 , MAX , TRS(s));
            // DB4("tmp = " , TRS(s) , val[valr[i]] , tmp);
            if(tmp == 0) cout << -1 << endl;
            else if(tmp == 1) cout << 0 << endl;
            else cout << queryval(valr[i] , 1 , INF , 1 , tmp - 1) << endl;
        }
        if(type == "undo"){
            cin >> xx;
            idxr[i] = idxr[i - xx - 1] , valr[i] = valr[i - xx - 1];
            // DBGG("rrr = " , i - xx - 1 , idx[]);
        }
        cout << flush;
        // DBGG("why = " , queryidx(idxr[1] , 1 , MAX , 1));
        //     if(xx == 1) return 0;
    }
    return 0;
}