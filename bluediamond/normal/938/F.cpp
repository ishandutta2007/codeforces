#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

int getlog2(int x){
        if(x==1){
                return 0;
        }else{
                return 1+getlog2(x/2);
        }
}

const int N=5000+7;
int n;
int k;
int deltotal;
bool reach[N][N];
string what[N];
string init;

signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        cin>>init;
        n=(int)init.size();
        k=getlog2(n);
        deltotal=(1<<k)-1;

        for(int i=1;i<=n;i++){
                what[i]="|";
        }

        reach[0][0]=1;
        for(int i=0;i<k;i++){
                reach[(1<<i)][(1<<i)]=1;
        }

        for(int len=0;len<n-deltotal;len++){
                char minch='|';
                for(int mask=0;mask<(1<<k);mask++){
                        int i=mask+len;
                        if(reach[i][mask]){

                                for(int bit=0;bit<k;bit++){
                                        if(!(mask&(1<<bit))){
                                                reach[i+(1<<bit)][mask+(1<<bit)]=1;
                                        }
                                }
                                minch=min(minch,init[i]);
                        }
                }
                for(int mask=0;mask<(1<<k);mask++){
                        int i=mask+len;
                        if(reach[i][mask]&&init[i]==minch){
                                reach[i+1][mask]=1;
                        }
                }
                what[len+1]=what[len];
                what[len+1]+=minch;
        }

        cout<<what[n-deltotal]<<"\n";
}