//write by Tiancheng Chu(CTC)
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         Buddha Bless      Never BUG
*/
#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<cfloat>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<functional>
#include<ctype.h>
#include<stdlib.h>
#include<list>
#include<deque>
#include<numeric>
#include<utility>
#include<sstream>
#include<ctime>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<complex>
#include<memory>
#pragma GCC optimize(1)
#pragma G++ optimize(1)
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(3)
#pragma GCC optimize(4)
#pragma G++ optimize(4)
#pragma GCC optimize(5)
#pragma G++ optimize(5)
#pragma GCC optimize(6)
#pragma G++ optimize(6)
#pragma GCC optimize(7)
#pragma G++ optimize(7)
#pragma GCC optimize(8)
#pragma G++ optimize(8)
#pragma GCC optimize(9)
#pragma G++ optimize(9)
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define FORN(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define forn(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define itn int
#define ll long long
#define LL long long
#define MP make_pair
//#define mp make_pair
#define PB push_back
#define pb push_back
#define BIG 2000000000
#define SMA -2000000000
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define PII pair<int,int>
#define pii pair<int,int>
#define tri pair<int,pii>
#define zero(a) memset(a,0,sizeof(a))
#define pi 3.14159265358
#define rt return
#define INF 1<<29
#define LINF (1LL)<<60
#define F first
#define S second
#define fi first
#define se second
#define st first
#define nd second

//classes:
int n,d;
int s[200005],p[200005],ranke,ss,pp;
bool check(int x)
{
    for(int i=x;i<n;i++)
        if(s[i]+p[n-1-(i-x)]>ranke) return 0;
    return 1;
}

//programs:
void inputs()
{
    cin>>n>>d;
    n--;
    for(int i=0;i<d-1;i++)
        cin>>s[i];
    cin>>ss;
    for(int i=d-1;i<n;i++)
        cin>>s[i];
    cin>>pp;
    for(int j=0;j<n;j++)
        cin>>p[j];
    d--;
}
void solve()
{
    ranke=ss+pp;
    int l=0,r=n+1;
    while(l<r-1)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    if(r>=2 and check(r-2)) cout<<r-1;
    else if(r>=1 and check(r-1)) cout<<r;
    else if(check(r)) cout<<r+1;
    else cout<<r+2;
}
void outputs()
{
    ;
}
/*
6 4
50 40 30 20 6 1
43 38 29 18 3 1
*/
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    inputs();
    solve();
    outputs();

    //cout<<clock();
    //system("pause");
    rt 0;
}

/*
 *                             UM.
 *                            J@B@1                                                                    iO@1
 *                           Y@@@B@BB.                                                              7B@B@B@
 *                          :@B@i,B@B@O                                                          ,Z@B@B@B@Br
 *                          @B@q   i@B@BS                                                      7@B@@@O5vMB@q
 *                         8@@B      LB@B@i                                                  FB@@@BNjYjLE@B@
 *                        ,B@B:        0@@@Z                                               P@B@BM1JJ125JPB@B
 *                        B@BB          :@B@B                                            XB@B@Z2LuU52F2u2@B@.
 *                       :@B@             @@@B:                                        v@B@B8uJj51F1525uUB@B7
 *                       @B@O              0@@B.               ..::ir7vvYUuU777r::.   B@B@OULU2F2F151F11Y@B@S
 *                       B@B,               8B@B  :ruXMB@B@B@B@B@B@B@B@B@B@@@B@B@B@B@B@B@5Jj1211F1F1F2FUJO@BB
 *                      U@B@                 @B@B@B@B@B@@@B@B@B@MMqPS5JuYL7rq@B@OBB@B@B8Yu211F1515251515YGB@@
 *                      @B@u                 v@@@@MSur:.                    LB@MvvjJuU5YU252F1F1F25251F2uX@@@
 *                      @@@.                                                N@BML2U2UUU12F15252525251515Jk@@B
 *                     r@B@                                                 YB@Bju52121252515252F15251F2u5@B@
 *                     PB@B                                                  @@@PYUF151F25151F152F2F1F15jF@@B
 *                     @@BS                                                  N@@@UJ2F25252F251525151F1F1u5@B@
 *                     @@@7                                                   B@B@5Yj12F152F1F1F25252515jFB@B
 *                     B@Bi                                                    M@B@O2Luu52525212F151121UY1@B@7
 *                    O@B@:                                                     v@B@BMSuYJJuuUu2u2uujjYJJXB@B@M
 *                  7B@B@,                                                        1B@@@B@GPF1uujuu21PNMB@B@B@B@@
 *                 qB@B2                                                            i8B@B@B@B@B@@@@@B@B@B@q: @@@B
 *                MB@B:                                                                 7SBB@B@B@B@B@Zu:      @B@B
 *               ZB@B.                                              ,v.                                        @B@L
 *              LB@B,                         Y7                    @B@Bu                                      7@B@
 *   :B@B@@B2:  @@B7                         @B@Z                   r@B@B@BP:                                   B@BE
 *    BB@@@B@B@B@BE                        r@B@B                       7@B@B@B@Ou:                              iB@B
 *         :uM@@B@@2.           :7::::ivk@B@B@0                           :5B@B@B@B@B@B@G.                       @B@i
 *            BB@@@B@@         :@B@B@@@B@B@@1                                 .i5M@B@B@@@5                       M@@2
 *            B@B ,@B1          L0EZZG0F7:                                            .:,                        uB@MrP@M7
 *           2@B@                                                                                               ,O@B@B@B@B
 *           @B@1                                                     :@B@@@r                                :@@@@B@BL:,,
 *           B@Bi                         :2ZS;                      :@B@B@B@r                               L@B@B@BU
 *           @B@.                        @@@B@B@                     vB@B@B@B5                                   @B@i
 *           B@B                        7B@B@B@BM                     OB@B@B@                                   ,B@B
 *           @B@                         @B@B@@@i                       rL7.                                    B@BM
 *           B@B7.:                       NB@@M.                                                               .@B@.
 *  .;JEB@@@B@B@B@B@.                                                                                       .  @B@u
 *@@@B@B@B@B@@@B@18U                                                                                      :B@B@B@BU,
 *7@BOui.    ,@@B                                                                                          SP@B@B@B@B@Or
 *            @@@U                                                                                           B@BJ.YO@B@B@i
 *            r@B@                                                                                         :B@Bk     .k@B@
 *             B@B@                                                                                       LB@@k         2i
 *              B@BM                                      .7jXEGqF7:                                     OB@@L
 *              .B@BM                                   .B@B@B@B@B@B@.                                 :@B@B:
 *               .B@B@                                   @@MYr::ivG@B                                .M@B@G
 *                 B@@@S                                                                           ,MB@B@,
 *                  v@@@BF                                                                      .1B@B@Br
 *                    2@@B@BL                                                                ,FB@@@B8,
 *                      r@B@B@BF,                                                        :YBB@B@B@B
 *                         L@B@B@B@P7,                                           .ivXB@B@B@B@B@M@B@
 *                            ,1B@B@B@B@@@BOP2L7i:,.              ..,:i7LSNB@@B@B@@@B@B@B@Z5v;.LB@@
 *                              @B@OEB@B@@@B@B@B@B@B@B@B@B@@@B@B@B@B@B@@@B@B@B@B@BM0SJ7i::::i:,u@B@
 *                              B@Bu ::i;7vu2XNGOMB@B@BMB@B@B@B@B@B@@@B1UFuj77ii:::::::iir;r;i.YB@B
 *                              @B@L.:i:i:i::::::::::..Y@B@BMYi:i;SB@B@N:.::i:iirir;r;rii::::ivO@B@
 *                              B@@X::,::::iirir;riri:E@B@1         ,@B@Br:;;r;rii:i::::i7JEB@@@@@B
 *                              @@@B@BBq5v7ii:::::::.2@@@i  ..,..     @B@@,,:::::irv2XMB@B@B@B@2@B@:
 *                             .B@BBB@@@B@B@B@BMNP5u7@B@1 .,,:,,  :.   @B@P50MB@B@B@B@B@@@BS:   @@B1
 *                             E@B@   ijGB@B@B@B@B@B@B@Bi .,:,,..@@B@7 B@B@B@B@B@B@BM57.        kB@B
 *                            .@B@:          .,ivu5Nq@B@u  ..,.. SB@B@@@B@PL7i,                 ,@B@
 *                            @@@8                   i@B@:    .     :B@B@@                       B@@2
 *                          i@@@@                     0@B@u          B@@B.                       vB@B
 *                         ,@B@G                       L@B@BOv:.:iFB@B@M                          @B@Bi
 *                          vNi                          S@@B@B@B@B@BM:                            MB@N
 */