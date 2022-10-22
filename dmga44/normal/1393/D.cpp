#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

char s[MAXN][MAXN];
int ac1[MAXN][MAXN];
int ac2[MAXN][MAXN];

int sum(int x1,int y1,int x2,int y2,int** ac)
{
    return ac[x2][y2]-ac[x1-1][y2]-ac[x2][y1-1]+ac[x1-1][y1-1];
}

int sum1(int x1,int y1,int x2,int y2)
{
    return ac1[x2][y2]-ac1[x1-1][y2]-ac1[x2][y1-1]+ac1[x1-1][y1-1];
}

int sum2(int x1,int y1,int x2,int y2)
{
    return ac2[x2][y2]-ac2[x1-1][y2]-ac2[x2][y1-1]+ac2[x1-1][y1-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
//    cin >> n >> m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
//        cin >> s[i];
        scanf("%s",&s[i]);
    }
    ll res=0;
    for(int cc=0;cc<26;cc++)
    {
//        db((char)('a'+cc))
        for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++)
                ac1[i][j]=ac2[i][j]=0;
//        db("xxx")
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='a'+cc)
                {
                    if((i+j)&1)
                        ac1[(i+j)/2+1][(i-j+m-1)/2+1]=1;
                    else
                        ac2[(i+j)/2+1][(i-j+m-1)/2+1]=1;
                }
//            if(!cc)
//            {
//                for(int i=0;i<2*n;i++)
//                {
//                    for(int j=0;j<2*n;j++)
//                        cout << ac1[i][j] << ' ';
//                    cout << '\n';
//                }
//                cout << '\n';
//                for(int i=0;i<2*n;i++)
//                {
//                    for(int j=0;j<2*n;j++)
//                        cout << ac2[i][j] << ' ';
//                    cout << '\n';
//                }
//                cout << '\n';
//
//            }
//        db("xxx")

        for(int i=1;i<MAXN;i++)
            for(int j=1;j<MAXN;j++)
            {
                ac1[i][j]=ac1[i][j]+ac1[i-1][j]+ac1[i][j-1]-ac1[i-1][j-1];
                ac2[i][j]=ac2[i][j]+ac2[i-1][j]+ac2[i][j-1]-ac2[i-1][j-1];
            }
//        db("xxx")

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='a'+cc)
                {
//                    db("")
//                    cout << i << ' ' << j << '\n';
                    if((i+j)&1)
                    {
///                        ac1[(i+j)/2+1][(i-j+m-1)/2+1]=1;
                        int ma=min(min(m-j,j+1),(n-i+1)/2);
                        int add=1;
                        for(int po=(1<<10);po;po>>=1)
                            if(add+po<=ma)
                            {
//                                db(add+po)
                                int px1=((i+j)>>1)+1;
                                int py1=((i-j+m-1)>>1)+1;
                                if(sum1(px1,py1,px1+add+po-1,py1+add+po-1)!=(add+po)*(add+po))
                                    continue;
//                                db(add+po)
                                int px2=((i+1+j)>>1)+1;
                                int py2=((i-j+m)>>1)+1;
                                if(sum2(px2,py2,px2+add+po-2,py2+add+po-2)!=(add+po-1)*(add+po-1))
                                    continue;
                                add+=po;
                            }
                        res+=add;
                    }
                    else
                    {
///                        ac2[(i+j)/2+1][(i-j+m-1)/2+1]=1;
                        int ma=min(min(m-j,j+1),(n-i+1)/2);
                        int add=1;
                        for(int po=(1<<10);po;po>>=1)
                            if(add+po<=ma)
                            {
                                int px1=((i+j)>>1)+1;
                                int py1=((i-j+m-1)>>1)+1;
                                if(sum2(px1,py1,px1+add+po-1,py1+add+po-1)!=(add+po)*(add+po))
                                    continue;
                                int px2=((i+1+j)>>1)+1;
                                int py2=((i-j+m)>>1)+1;
                                if(sum1(px2,py2,px2+add+po-2,py2+add+po-2)!=(add+po-1)*(add+po-1))
                                    continue;
                                add+=po;
                            }
                        res+=add;
                    }
                }
//        db("xxx")

    }
//    db(res)
    printf("%d\n",res);

    return 0;
}
/**
3 3
aaa
aaa
aaa

4 4
aaaa
aaaa
aaaa
aaaa

5 5
aaaaa
aaaaa
aaaaa
aaaaa
aaaaa

5 5
zbacg
baaac
aaaaa
eaaad
weadd

1 1
a

1 5
aaaaa

5 1
a
a
a
a
a
**/