#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
const int maxk = 12+2;
const int maxmask = (1 << 4) + 5;
const int mod = 1e9 + 7;
inline void add(int &target,int val){
    (target += val) %= mod;
}
int n,K,m;
int dp[maxn][maxmask][maxk];
map<pair<int,int>,int> comp_mem;
map<int,pair<int,int> > decmp_mem;
int comp(int k,int mask){
    auto key = make_pair(k,mask);
    if (comp_mem.count(key))return comp_mem[key];
    int sz = comp_mem.size() ;
    //cout<<sz<<endl;
    comp_mem[key] = sz;
    decmp_mem[sz] = key;
    return sz;
}
typedef vector<vector<int> > mat;
mat create_zero(int sz){
    mat res(sz,vector<int>(0));
    for (int i=0;i<sz;i++){
        res[i].resize(sz);
        for (int j=0;j<sz;j++){
            res[i][j] = 0;
        }
    }
    return res;
}
mat create_eye(int sz){
    mat res(sz,vector<int>(0));
    for (int i=0;i<sz;i++){
        res[i].resize(sz);
        for (int j=0;j<sz;j++){
            res[i][j] = 0;
        }
        res[i][i] = 1;
    }
    return res;
}
mat operator * (const mat & x,const mat &y){
    assert(x[0].size() == y.size());
    int sz = x.size();
    mat res = create_zero(sz);
    for (int i = 0;i < sz;i++){
        for (int j=0;j<sz;j++){
            for (int k=0;k<sz;k++){
                add(res[i][j] , 1ll * x[i][k] * y[k][j] % mod);
            }
        }
    }
    return res;
}
mat powmod(mat x,int y){
    mat res = create_eye(x.size());
    while (y){
        if (y&1){
            res = res * x;
        }
        y >>= 1;
        x = x * x;
    }
    return res;
}
void add_trans(mat& trans,int x,int y,int s){
    //cout<<x<<" "<<y<<" "<<s<<endl;
    trans[y][x] += s;
}
void debug(mat x){
    for (auto row : x){
        for (auto item : row){
            cout<<item<<" ";
        }
        cout<<endl;
    }
}
int main(){
    auto start_ = clock();
    scanf("%d%d%d",&n,&K,&m);
    for (int k=0;k<=K;k++){
        for (int mask = 0;mask < (1<<m);mask++){
            comp(k,mask);
        }
    }
    int SZ = (K+1) * (1<< m);
    cerr<<SZ<<endl;
    mat trans = create_zero(SZ);
    for (int mask = 0;mask < (1<<m);mask ++){
        for (int k=0;k<=K;k++){
            //not use
            add_trans(trans,comp(k,mask),comp(k,mask>>1),1);
            //use
            if (k == K)continue;
            add_trans(trans,comp(k,mask),comp(k+1,(mask>>1) | (1<<(m-1))),1 + __builtin_popcount(mask));
        }
    }
    //debug(trans);
    mat final_trans = powmod(trans,n);
    //cout<<endl;
    //debug(final_trans);
//    for (int k=0;k<=K;k++){
//        for (int mask = 0;mask < (1<<m);mask ++){
//            cout<<"("<<k<<","<<mask<<") = "<< comp(k,mask)<<endl;
//        }
//    }
//    for (int mask = 0;mask < (1 << m);mask ++){
//        for (int k=0;k<=K;k++){
//            int id1 = comp(k,mask);
//            int id2 = comp(k,mask>>1);
//            int id3 = comp(k+1,(mask>>1) | (1<<(m-1)));
//            assert(trans[id2][id1] == 1);
//            if (k != K)
//            assert(trans[id3][id1] == 1+__builtin_popcount(mask));
//            cout<<"trans:("<<k<<","<<mask<<") -> ("<<k<<","<<(mask>>1)<<"): "<<1<<endl;
//            cout<<"trans:("<<k<<","<<mask<<") -> ("<<k+1<<","<<((mask>>1) | (1<<(m-1)))<<"): "<<1+__builtin_popcount(mask)<<endl;
//
//            //not use
//            add(dp[i+1][(mask>>1)][k],dp[i][mask][k]);
//            //use
//            add(dp[i+1][(mask>>1) | (1<<(m-1))][k+1],1ll * dp[i][mask][k] * (1+__builtin_popcount(mask) ) % mod);
//        }
//    }

    int col_id = comp(0,0);
    int ans = 0;
    for (int mask = 0;mask < (1 << m);mask ++){
        int k =K;
        int row_id = comp(k,mask);
//        cout<<"("<<row_id<<","<<col_id<<")"<<endl;
        add(ans,final_trans[row_id][col_id]);
    }
    cout<<ans<<endl;
    auto end_ = clock();
    cerr<<"runtime: "<<end_ - start_<<endl;
    return 0;
}