#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

vector < pair <int,int> > q;
int dp[51][51];
int mod=1000000007;
int dp2[201][51][51];
int C[55][55];
int dpa[51][51][51];
int dpb[51][51][51];
int go[51][51][51][51];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    for(int i=0;i<=50;++i) {
        C[i][0]=1;
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    int n,k,c0=0,c1=0,a;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        if (a==50) c0++;
        else c1++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    q.push_back(make_pair(0,0));
    for(int i=0;i<q.size();++i) {
        int n0=q[i].first,n1=q[i].second;
        for(int a=0;a+n0<=c0&&50*a<=k;++a)
            for(int b=0;b+n1<=c1;++b)
                if ((a+b>0)&&a*50+b*100<=k) {
                    int na=n0+a,nb=n1+b;
                    if (na) {
                        if (na+nb!=n) --na;
                    }
                    else {
                        if (na+nb!=n) {
                            --nb;
                            if (k<100) continue;
                        }
                    }
                    if (dp[na][nb]==-1) {
                        q.push_back(make_pair(na,nb));
                        dp[na][nb]=dp[n0][n1]+1+(na+nb!=n);
                    }
                }
    }
    cout << dp[c0][c1] << endl;

    for(int ca=0;ca<=c0;++ca)
        for(int na=0;na<=c0;++na)
            for(int to=0;ca+to<=c0;++to) {
                if (ca+to>=na&&50*to<=k) {
                    int from=ca+to-na;
                    dpa[ca][na][to]=1LL*C[c0-ca][to]*C[ca+to][from]%mod;
                }
            }

    for(int cb=0;cb<=c1;++cb)
        for(int nb=0;nb<=c1;++nb)
            for(int to=0;cb+to<=c1;++to) {
                if (cb+to>=nb&&100*to<=k) {
                    int from=cb+to-nb;
                    dpb[cb][nb][to]=(1LL*C[c1-cb][to]*C[cb+to][from])%mod;
                }
            }
    for(int cb=0;cb<=c1;++cb)
        for(int nb=0;nb<=c1;++nb)
            for(int to=0;to<=c1;++to) {
                dpb[cb][nb][to]=((to>0 ? dpb[cb][nb][to-1] : 0)+dpb[cb][nb][to])%mod;
            }

    for(int ca=0;ca<=c0;++ca)
        for(int na=0;na<=c0;++na)
            for(int to=0;ca+to<=c0;++to)
                if (dpa[ca][na][to]) {
                    int from=ca+to-na;
                    for(int cb=0;cb<=c1;++cb)
                        for(int nb=0;nb<=c1;++nb) {
                            int r=min((k-50*to)/100,(k-50*from)/100+nb-cb);
                            r=min(r,c1);
                            int up=-1;
                            if (to==0) up=0;
                            if (na+nb!=n&&from==0) {
                                up=max(up,nb-cb);
                            }
                            if (r>=up&&r>=0) {
                                long long mult=dpb[cb][nb][r];
                                if (up>=0) mult-=dpb[cb][nb][up];
                                go[ca][cb][na][nb]=(go[ca][cb][na][nb]+1LL*dpa[ca][na][to]*mult)%mod;
                            }
                        }
                }

/*  for(int ca=0;ca<=c0;++ca)
        for(int cb=0;cb<=c1;++cb)
            for(int na=0;na<=c0;++na)
                for(int nb=0;nb<=c1;++nb)
                    printf("(%d,%d) - > (%d,%d) = %d\n",ca,cb,na,nb,go[ca][cb][na][nb]);
    */
    int tot=dp[c0][c1];
    dp2[0][0][0]=1;
    for(int it=0;2*it<=(tot+1);++it) {
        if (it<=tot) {
            for(int ca=0;ca<=c0;++ca)
                for(int cb=0;cb<=c1;++cb)
                    if (dp2[it][ca][cb]) {
                        for(int na=0;na<=c0;++na)
                            for(int nb=0;nb<=c1;++nb) {
                                dp2[it+1][na][nb]=(dp2[it+1][na][nb]+1LL*dp2[it][ca][cb]*go[ca][cb][na][nb])%mod;
                            }
                        /*for(int a=0;a+ca<=c0;++a)
                            for(int b=0;b+cb<=c1;++b) {
                                if ((a+b>0)&&a*50+b*100<=k) {
                                    int na=a+ca,nb=b+cb,mult=1LL*C[c0-ca][a]*C[c1-cb][b]%mod;
                                    if (na+nb!=n) {
                                        if (na) {
                                            if (na-1!=ca||nb!=cb)
                                                dp2[it+1][na-1][nb]=(dp2[it+1][na-1][nb]+1LL*dp2[it][ca][cb]*mult%mod*na)%mod;
                                        }
                                        if (nb&&k>=100) {
                                            if (na!=ca||nb-1!=cb)
                                                dp2[it+1][na][nb-1]=(dp2[it+1][na][nb-1]+1LL*dp2[it][ca][cb]*mult%mod*nb)%mod;
                                        }
                                    } else
                                        if (na!=ca||nb!=cb) dp2[it+1][na][nb]=(dp2[it+1][na][nb]+1LL*dp2[it][ca][cb]*mult)%mod;
                                }
                            }*/
                    }
        } else {
        
        }
    }
    cout << dp2[(tot+1)/2][c0][c1] << endl;
    return 0;
}