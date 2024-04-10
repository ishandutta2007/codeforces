#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define WHILE(n) while(scanf("%d",&n)==1)
#define WHILE_(n) while(scanf("%d",&n)==1 && n)
#define WHILENM(n,m) while(scanf("%d%d",&n,&m)==2)
#define WHILENM_(n,m) while(scanf("%d%d",&n,&m)==2 && n && m)
#define INf 0x3f3f3f3f
#define MEM(i,j) memset(i,j,sizeof i)
#define a first
#define b second
#define pb push_back
#define mp make_pair

/// --------default_code----------
#define MAX 510
#define INF 0x3f3f3f3f
#define MOD 1000000007

int main()
{
    int n;
    WHILE(n)
    {
        map<PII,PII> s; /// 1,2 3 key
        int x[3] , ans = 1 , num = 0;
        PII anss;
        REP(i,n)
        {
            scanf("%d%d%d",&x[0],&x[1],&x[2]);
            sort(x,x+3);
            if(x[0] > num)ans = 1 , anss.a = i , num = x[0];
            PII q;
            q = mp(x[0],x[1]);

            if(s.count(q)){
                int qw = s[q].a+x[2];
                qw = min(qw , x[0]);
                if(qw > num)
                    ans = 2 , anss=mp(s[q].b , i) , num = qw;
            }
            q = mp(x[0],x[2]);
            if(s.count(q)){
                int qw = s[q].a+x[1];
                qw = min(qw , x[0]);
                if(qw > num)
                    ans = 2 , anss=mp(s[q].b , i) , num = qw;
            }
            q = mp(x[1],x[2]);
            if(s.count(q)){
                int qw = s[q].a+x[0];
                qw = min(qw , x[1]);
                if(qw > num)
                    ans = 2 , anss=mp(s[q].b , i) , num = qw;
            }
//            if(s.count(q))cout<<"here"<<endl;


            q = mp(x[0],x[1]);
            if(s.count(q))s[q] = max( s[q] , mp( x[2] , i));
            else s[q]=mp( x[2] , i);

            q = mp(x[0],x[2]);
            if(s.count(q))s[q] = max( s[q] , mp( x[1] , i));
            else s[q]=mp( x[1] , i);

            q = mp(x[1],x[2]);
            if(s.count(q))s[q] = max( s[q] , mp( x[0] , i));
            else s[q]=mp( x[0] , i);
        }
//        printf("num = %d\n",num);
        if(ans == 1) printf("1\n%d\n",anss.a+1);
        else printf("2\n%d %d\n",anss.a+1,anss.b+1);
    }
    return 0;
}