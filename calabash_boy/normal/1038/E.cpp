
#include<bits/stdc++.h>
#define c1 dfdfdf
using namespace std;
#define int ll
typedef long long ll;
int n;
typedef pair<int,int> pii;
typedef vector<int> vi;
map<pii,vector<int> > Card;
map<pii,ll> Sum;
ll dp[1<<11][5][5];
vector<int> Bit[12];
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
inline int id(pair<int,int> card){
    if (card.first == 1){
        return card.second-1;
    }else if (card.first == 2){
        return 2 + card.second;
    }else if (card.first == 3){
        return 4+card.second;
    }else{
        return 9;
    }
}
inline void maxx(ll & tar,ll val){
    tar = max(tar,val);
}
inline void upd(int now,int C1,int C2){
    for (auto &item : Card){
        int dig = id(item.first);
        vi & card = item.second;
        if (now & (1 << dig))continue;
        int nxt = now | (1<<dig);
        maxx(dp[nxt][C1][C2],dp[now][C1][C2]);
        if (card.size() == 0)continue;

        ll val_2 = Sum[item.first];
        ll val_1 = val_2;
        bool flag = card.size() >=2;
        if (card.size() %2 == 1){
            val_2 -= card[0];
        }else{
            val_1 -= card[0];
        }
        int l = item.first.first;
        int r = item.first.second;
        ll now_val = dp[now][C1][C2];
        //cout<<now<<" "<<nxt<<" "<<C1<<" "<<C2<<"  :"<<now_val<<endl;
        //left
        if (l == C1){
            //2
            int c1 = min(l,C2);
            int c2 = max(l,C2);
            if (flag)
            maxx(dp[nxt][c1][c2],now_val + val_2);
            //1
            c1 = min(r,C2);
            c2 = max(r,C2);
            maxx(dp[nxt][c1][c2],now_val + val_1);
        }
        if (r == C1){
            //2
            int c1 = min(r,C2);
            int c2 = max(r,C2);
            if (flag)
            maxx(dp[nxt][c1][c2],now_val + val_2);
            //1
            c1 = min(l,C2);
            c2 = max(l,C2);
            maxx(dp[nxt][c1][c2],now_val + val_1);
        }
        //right
        if (l == C2){
            //2
            int c1 = min(l,C1);
            int c2 = max(l,C1);
            if (flag)
            maxx(dp[nxt][c1][c2],now_val + val_2);
            //1
            c1 = min(r,C1);
            c2 = max(r,C1);
            maxx(dp[nxt][c1][c2],now_val + val_1);
        }
        if (r == C2){
            //2
            int c1 = min(r,C1);
            int c2 = max(r,C1);
            if (flag)
            maxx(dp[nxt][c1][c2],now_val + val_2);
            //1
            c1 = min(l,C1);
            c2 = max(l,C1);
            maxx(dp[nxt][c1][c2],now_val + val_1);
        }
        //both
        if (l == C1 && l == C2){
            if (card.size()%2 == 0){
                maxx(dp[nxt][r][r],now_val + val_2);
            }
        }
        if (r == C1 && r == C2){
            if (card.size()%2 == 0){
                maxx(dp[nxt][l][l],now_val + val_2);
            }
        }
        
    }
}
ll ans =0;
signed main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int c1,c2,val;
        cin>>c1>>val>>c2;
        if (c1 > c2){
            swap(c1,c2);
        }
        Card[{c1,c2}].push_back(val);
    }
    for (auto &item : Card){
        auto &vals = item.second;
        sort(vals.begin(),vals.end());
        ll sum = 0;
        for (int val : vals){
            sum += val;
        }
        ans = max(ans,sum);
        Sum[item.first] = sum;
    }
    for (int i=0;i<(1<<10);i++){
        for (int j=0;j<=4;j++){
            for (int k=0;k<=4;k++){
                dp[i][j][k] = -inf;
            }
        }
    }
    for (int i=1;i<=4;i++){
            dp[0][i][i] = 0;
    }
    for (int i=0;i<(1<<10);i++){
        Bit[__builtin_popcount(i)].push_back(i);
    }
    for (int i=0;i<=9;i++){
        for (int  now : Bit[i]){
            for (int C1 = 1;C1 <=4;C1 ++){
                for (int C2 = C1;C2 <=4;C2++){
                    if (dp[now][C1][C2]>= 0)
                    upd(now,C1,C2);
                }
            }
        }
    }

    for (int i=0;i< (1<<10);i++){
        for (int j=1;j<=4;j++){
            for (int k=j;k<=4;k++){
                ans = max(ans,dp[i][j][k]);
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}