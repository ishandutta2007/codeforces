#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=14;
const int maxm=2005;

struct cll{
    int i,j,x;
};
int n,m;
int a[maxn][maxm];
vector<cll> v;
set<int> seq;
long long dp[maxn][(1<<12)+12];
int cst[(1<<12)+12];
vector<int> stt[(1<<12)];
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<(1<<12);i++){
        for(int j=0;j<(1<<12);j++){
            if((j&(~i))==0)stt[i].push_back(j);
        }
    }
    while(t--){
        cin>>n>>m;
        v.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                cll c;c.i=i;c.j=j;c.x=a[i][j];
                v.push_back(c);
            }
        }
        seq.clear();
        sort(v.begin(),v.end(),[&](cll a,cll b){
            return a.x>b.x;
        });
        for(int i=0;i<v.size();i++){
            int f=v[i].j;
            seq.insert(f);
            if(seq.size()>=n)break;
        }
        memset(dp,0xc0,sizeof(dp));
        dp[0][0]=0;
        int si=0;
        for(set<int>::iterator it=seq.begin();it!=seq.end();it++){
            ++si;
            int i=(*it);
            memset(cst,0xc0,sizeof(cst));
            for(int j=0;j<(1<<n);j++){
                for(int c=0;c<n;c++){
                    int cur=0;
                    for(int d=0;d<n;d++){
                        if((j>>d)&1)cur+=a[(d+c)%n+1][i];
                    }
                    cst[j]=max(cst[j],cur);
                }
            }
            for(int j=0;j<(1<<n);j++){
                for(int k=0;k<stt[j].size();k++){
                    //cerr<<j<<k<<endl;
                    dp[si][j]=max(dp[si][j],dp[si-1][stt[j][k]]+cst[j^(stt[j][k])]);
                }
                //cout<<i<<j<<':'<<dp[i][j]<<endl;
            }
        }
        cout<<dp[si][(1<<n)-1]<<'\n';
    }
    return 0;
}