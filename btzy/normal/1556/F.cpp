#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
constexpr int MAXN=14;
int arr[MAXN];
int masks[1<<MAXN];
int add_mod(int a, int b){
    return (a+b)%MOD;
}
int mult_mod(int a, int b){
    return (int)((((long long)a)*b)%MOD);
}
int neg_mod(int a){
    return (MOD-a)%MOD;
}
long long powmod(int base, int e){
    if (e==0)return 1;
    long long tmp=powmod(base,e/2);
    tmp*=tmp;
    tmp%=MOD;
    if(e&1){
        tmp*=base;
        tmp%=MOD;
    }
    return tmp;
}
int inv(int a){
    return (int)powmod(a,MOD-2);
}
int divi(int a, int b){
    return mult_mod(a, inv(b));
}
int prob[MAXN][MAXN];
int noneness_cache[MAXN][1<<MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            prob[i][j]=divi(arr[i],add_mod(arr[i],arr[j]));
        }
    }
    for(int i=0;i<n;++i){
        for(unsigned bm=0;bm<(1u<<n);++bm){
            int noneness=1;
            for(int k=0;k<n;++k){
                if((1u<<k)&bm){
                    noneness=mult_mod(noneness,prob[i][k]);
                }
            }
            noneness_cache[i][bm]=add_mod(1,neg_mod(noneness));
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        for(unsigned bm=0;bm!=(1u<<n);++bm){
            if((bm&(1u<<i))==0){
                masks[bm]=0;
            }
            else if(bm==(1u<<i)){
                masks[bm]=1;
            }
            else{
                int total=0;
                auto bm_popcnt=__builtin_popcount(bm);
                for(unsigned b2=(bm-1)&bm;b2!=0;b2=(b2-1)&bm){
                    int eff=masks[b2];
                    unsigned diff=bm^b2;
                    for(int j=0;j<n;++j){
                        if((1<<j)&diff){
                            /*
                            int noneness=1;
                            for(int k=0;k<n;++k){
                                if((1<<k)&b2){
                                    noneness=mult_mod(noneness,prob[j][k]);
                                }
                            }
                            eff=mult_mod(eff,add_mod(1,neg_mod(noneness)));
                            */
                            eff=mult_mod(eff,noneness_cache[j][b2]);
                        }
                    }
                    auto b2_popcnt=__builtin_popcount(b2);
                    if((bm_popcnt-b2_popcnt)&1){
                        total=add_mod(total,eff);
                    }
                    else{
                        total=add_mod(total,neg_mod(eff));
                    }
                }
                masks[bm]=total;
            }
        }
        ans=add_mod(ans,masks[(1u<<n)-1u]);
        for(unsigned bm=0;bm!=(1u<<n);++bm){
            masks[bm]=0;
        }
    }
    cout<<ans<<'\n';
}