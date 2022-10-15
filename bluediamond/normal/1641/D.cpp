#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef unsigned long long ull;

const int N=(int)1e5;
const int M=5;

int a[N][M],b[N][M],guys[N];
int w[N];
ull where[N*M];

bool cmp(int i,int j){
        return w[i]<w[j];
}

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int n,m;
        cin>>n>>m;
        vector<int> values;

        for(int j=0;j<n*m;j++){
                where[j]=-1;
        }

        for(int i=0;i<n;i++){
                guys[i]=i;
                for(int j=0;j<m;j++){
                        cin>>a[i][j];
                        values.push_back(a[i][j]);
                }
                cin>>w[i];
        }
        sort(values.begin(),values.end());
        values.resize(unique(values.begin(),values.end())-values.begin());

        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        a[i][j]=lower_bound(values.begin(),values.end(),a[i][j])-values.begin();
                        b[i][j]=a[i][j];
                }
        }



        sort(guys,guys+n,cmp);
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        a[i][j]=b[guys[i]][j];
                }
        }
        sort(w,w+n);

        int best=(int)2e9+7;

        for(int l=0;l<n;l+=64){
                int r=min(n,l+64)-1;
                for(int i=l;i<=r;i++){
                        for(int j=0;j<m;j++){
                                where[a[i][j]]^=(1ULL<<(i-l));
                        }
                }
                ull goodtot=0;
                for(int j=l;j<=r;j++){
                        goodtot|=(1ULL<<(j-l));
                }
                for (int i=0;i<n;i++){
                        ull good=goodtot;
                        for(int j=0;j<m;j++){
                                good&=where[a[i][j]];
                        }
                        if(good!=0){
                                best=min(best,w[i]+w[l+__builtin_ctzll(good)]);
                        }
                }
                for(int i=l;i<=r;i++){
                        for(int j=0;j<m;j++){
                                where[a[i][j]]=-1;
                        }
                }
        }


        if(best==(int)2e9+7){
                best=-1;
        }
        cout<<best<<"\n";


        return 0;
}