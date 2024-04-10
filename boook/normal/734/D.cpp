#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL , LL> PII;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define RREP(i,j,k) for(int i=j;i>=k;i--)
#define MEM(i,j) memset(i,j,sizeof i)
#define WHILE(n) while(~scanf("%d",&n))
#define WHILE_(n) while(~scanf("%d",&n) && n)
#define WHILENM(n,m) while(~scanf("%d%d",&n,&m))
#define WHILENM_(n,m) while(~scanf("%d%d",&n,&m) && (n || m) )
#define pb push_back
#define mp make_pair
#define A first
#define B second
#define AC 53LL
#define AMOD 1000000079LL
#define debug 0
#define DB() if(debug)

/// ----------- default code ----------------
#define MAX 10
#define INF 100000000000LL

LL n;
PII kg , q;
PII good[10];
LL ok[10];
LL F(PII now){
    PII u = mp(kg.A-now.A , kg.B-now.B);
    if(u.A == 0){
        if(u.B > 0)return 3; /// left
        else if(u.B < 0)return 4;
    }
    else if(u.B == 0){
        if(u.A > 0)return 1; /// up
        else if(u.A < 0)return 6;
    }
    PII qq = mp(abs(u.A) , abs(u.B));
    if(qq.A != qq.B)return -1;
    if(u.A > 0 && u.B > 0)return 0;
    if(u.A < 0 && u.B < 0)return 7;
    if(u.A > 0 && u.B < 0)return 2;
    if(u.A < 0 && u.B > 0)return 5;


}
/*
012
3 4
567
*/
void INS(LL to , PII now , LL key){
    if(good[to] == mp(INF,INF))good[to] = now , ok[to] = key;
    else {
        PII p = good[to];
        LL a = abs(p.A - kg.A) + abs(p.B - kg.B);
        LL b = abs(now.A - kg.A) + abs(now.B - kg.B);
        if(b < a)good[to] = now , ok[to] = key;
    }
}
LL G(char c , LL in){
    if(c == 'Q')return 1;
    if(c == 'B')return (in==0 || in==2 || in==5 || in==7);
    return (in==1 || in==3 || in==4 || in==6);
}
int main()
{
    cin.tie() , cout.sync_with_stdio(0);
    while(cin>>n){
        REP(i,10)good[i] = mp(INF,INF) , ok[i] = 0;
        char c;
        cin>>kg.A>>kg.B;
        REP(i,n){
            cin>>c>>q.A>>q.B;
            LL in = F(q);
            if(in != -1){
                LL key = G(c , in);
//                cout<<"in = "<<key<<endl;
                INS(in , q , key);
            }
        }
//        cout<<"here"<<endl;
        LL ans = 0;
        REP(i,8){
            if(good[i] == mp(INF,INF))continue;
            if(ok[i])ans = 1;
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}