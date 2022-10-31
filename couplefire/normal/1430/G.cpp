#include <bits/stdc++.h>

using namespace std;

struct edge_t{
    int x,y,w;

    int other(int nod){
        return x ^ y ^ nod;
    }
};

int n,m;
long long dp[1 << 18];
vector<edge_t> graph[20];
int fathers[20];
int ant[1 << 18];
int ans[20];

int main() {

    scanf("%d %d",&n,&m);

    for(int i = 1;i <= m;i++){
        edge_t tmp;
        scanf("%d %d %d",&tmp.x,&tmp.y,&tmp.w);
        graph[tmp.x].push_back(tmp);
        fathers[tmp.y] |= 1 << (tmp.x - 1);
    }

    for(int conf = 0;conf < (1 << n);conf++){
        dp[conf] = 1e18;
    }

    dp[0] = 0;

    for(int conf = 0;conf < (1 << n);conf++){

        if(dp[conf] == 1e18){
            continue;
        }

        int exp_conf = 0;
        long long weights = 0;

        for(int i = 1;i <= n;i++){
            if(((conf >> (i - 1)) & 1) == 0 && (fathers[i] & conf) == fathers[i]){
                exp_conf |= (1 << (i - 1));
            }
            if((conf >> (i - 1)) & 1){
                for(auto it:graph[i]){
                    if(((conf >> (it.y - 1)) & 1) == 0){
                        weights += it.w;
                    }
                }
            }
        }

        for(int conf2 = exp_conf;conf2;conf2 = (conf2 - 1) & exp_conf){
            if(dp[conf | conf2] > dp[conf] + weights){
                ant[conf | conf2] = conf2;
                dp[conf | conf2] = dp[conf] + weights;
            }
        }
    }

    int conf = (1 << n) - 1;
    int lst = 0;

    while(conf){
        //printf("%d %d\n",conf,ant[conf]);
        for(int i = 1;i <= n;i++){
            if((ant[conf] >> (i - 1) & 1)){
                ans[i] = lst;       
            }
        }
        conf ^= ant[conf];
        lst++;
    }

    for(int i = 1;i <= n;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}