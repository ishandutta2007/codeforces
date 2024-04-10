#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 100;
constexpr int MOD = 1000000007;
constexpr int MAXTOLERANCE = 10000001; //10001; // really? TODO
int c[MAXN], b[MAXN], magic[MAXN];
int dp1[MAXTOLERANCE], dp2[MAXTOLERANCE];
int coalesce[MAXTOLERANCE+1];
int* const coal=coalesce+MAXTOLERANCE/2;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n;
    for (int i=0;i<n;++i){
        cin>>c[i];
    }
    for(int i=1;i<n;++i){
        cin>>b[i];
    }
    cin>>q;
    for(int j=0;j<q;++j){
        int x;
        cin>>x;
        /*if (x>MAXN){
            cout<<0<<'\n';
            continue;
        }*/
        magic[0]=x;
        for(int i=1;i<n;++i){
            magic[i]=magic[i-1]+b[i];
        }
        int* prev=dp1+MAXTOLERANCE/2;
        //fill_n(prev-MAXTOLERANCE/2, MAXTOLERANCE, 0);
        prev[x]=1;
        int prev_low=x;
        int prev_high=x;
        int* curr=dp2+MAXTOLERANCE/2;
        //fill_n(curr-MAXTOLERANCE/2, MAXTOLERANCE, 0);
        for(int i=0;i<n-1;++i){
            //fill_n(curr-MAXTOLERANCE/2, MAXTOLERANCE, 0);
            //fill_n(coal-MAXTOLERANCE/2, MAXTOLERANCE+1, 0);
            // TODO: optimize
            int coal_low=LLONG_MAX;
            int coal_high=LLONG_MIN;
            for(int k=prev_low;k<=prev_high;++k){
                int start = max(k, 0ll);
                if (start <= c[i] && prev[k]>0){
                    int c_start = min(max(magic[i+1]-(c[i]-k), -MAXTOLERANCE/2), MAXTOLERANCE/2+1);
                    int c_end = min(max(magic[i+1]-(start-k)+1, -MAXTOLERANCE/2), MAXTOLERANCE/2+1);
                    coal[c_start]+=prev[k];
                    coal[c_start]%=MOD;
                    coal[c_end]+=(MOD-prev[k]);
                    coal[c_end]%=MOD;
                    coal_low=min(coal_low,c_start);
                    coal_high=max(coal_high,c_end-1);
                }

                /*for(int kk=start;kk<=c[i];++kk){
                    int ind = magic[i+1]-(kk-k);
                    if (ind >= -MAXTOLERANCE/2 && ind <= MAXTOLERANCE/2){
                        curr[ind]+=prev[k];
                        curr[ind]%=MOD;
                    }
                }*/
            }
            int cum=0;
            for(int k=coal_low;k<=coal_high;++k){
                cum+=coal[k];
                cum%=MOD;
                curr[k]=cum;
            }
            fill(coal+coal_low,coal+coal_high+2,0);
            fill(prev+prev_low, prev+prev_high+1,0);
            prev_low=coal_low;
            prev_high=coal_high;
            swap(prev, curr);
            /*for(int k=-10;k<=10;++k){
                cout<<' '<<prev[k];
            }
            cout<<endl;
            cout<< prev_low<<' '<<prev_high<<endl;*/
        }
        int ans=0;
        {
            //fill_n(curr-MAXTOLERANCE/2, MAXTOLERANCE, 0);
            // TODO: optimize
            for(int k=prev_low;k<=prev_high;++k){
                int start = max(k, 0ll);
                for(int kk=start;kk<=c[n-1];++kk){
                    ans+=prev[k];
                    ans%=MOD;
                }
            }
            fill(prev+prev_low,prev+prev_high+1,0);
        }
        cout<<ans<<'\n';
    }
}