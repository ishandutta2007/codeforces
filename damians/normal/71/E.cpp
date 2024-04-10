#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

map<string,int> st;

void rub()
{
    st["H"]=1 ;
st["He"]=2 ;
st["Li"]=3 ;
st["Be"]=4 ;
st["B"]=5 ;
st["C"]=6 ;
st["N"]=7 ;
st["O"]=8 ;
st["F"]=9 ;
st["Ne"]=10 ;
st["Na"]=11 ;
st["Mg"]=12 ;
st["Al"]=13 ;
st["Si"]=14 ;
st["P"]=15 ;
st["S"]=16 ;
st["Cl"]=17 ;
st["Ar"]=18 ;
st["K"]=19 ;
st["Ca"]=20 ;
st["Sc"]=21 ;
st["Ti"]=22 ;
st["V"]=23 ;
st["Cr"]=24 ;
st["Mn"]=25 ;
st["Fe"]=26 ;
st["Co"]=27 ;
st["Ni"]=28 ;
st["Cu"]=29 ;
st["Zn"]=30 ;
st["Ga"]=31 ;
st["Ge"]=32 ;
st["As"]=33 ;
st["Se"]=34 ;
st["Br"]=35 ;
st["Kr"]=36 ;
st["Rb"]=37 ;
st["Sr"]=38 ;
st["Y"]=39 ;
st["Zr"]=40 ;
st["Nb"]=41 ;
st["Mo"]=42 ;
st["Tc"]=43 ;
st["Ru"]=44 ;
st["Rh"]=45 ;
st["Pd"]=46 ;
st["Ag"]=47 ;
st["Cd"]=48 ;
st["In"]=49 ;
st["Sn"]=50 ;
st["Sb"]=51 ;
st["Te"]=52 ;
st["I"]=53 ;
st["Xe"]=54 ;
st["Cs"]=55 ;
st["Ba"]=56 ;
st["La"]=57 ;
st["Ce"]=58 ;
st["Pr"]=59 ;
st["Nd"]=60 ;
st["Pm"]=61 ;
st["Sm"]=62 ;
st["Eu"]=63 ;
st["Gd"]=64 ;
st["Tb"]=65 ;
st["Dy"]=66 ;
st["Ho"]=67 ;
st["Er"]=68 ;
st["Tm"]=69 ;
st["Yb"]=70 ;
st["Lu"]=71 ;
st["Hf"]=72 ;
st["Ta"]=73 ;
st["W"]=74 ;
st["Re"]=75 ;
st["Os"]=76 ;
st["Ir"]=77 ;
st["Pt"]=78 ;
st["Au"]=79 ;
st["Hg"]=80 ;
st["Tl"]=81 ;
st["Pb"]=82 ;
st["Bi"]=83 ;
st["Po"]=84 ;
st["At"]=85 ;
st["Rn"]=86 ;
st["Fr"]=87 ;
st["Ra"]=88 ;
st["Ac"]=89 ;
st["Th"]=90 ;
st["Pa"]=91 ;
st["U"]=92 ;
st["Fm"]=100;
st["Np"]=93 ;
st["Pu"]=94 ;
st["Am"]=95 ;
st["Cm"]=96 ;
st["Bk"]=97 ;
st["Cf"]=98 ;
st["Es"]=99 ;
st["Md"]=101 ;
st["No"]=102 ;
st["Lr"]=103 ;
st["Rf"]=104 ;
st["Db"]=105 ;
st["Sg"]=106 ;
st["Bh"]=107 ;
st["Hs"]=108 ;
st["Mt"]=109 ;
st["Ds"]=110 ;
st["Rg"]=111 ;
st["Cn"]=112 ;
st["Uut"]=113 ;
st["Uuq"]=114 ;
st["Uup"]=115 ;
st["Uuh"]=116 ;
st["Uus"]=117 ;
st["Uuo"]=118 ;

}

int n,k;
vector<int> v,w;
vector<string> v1,w1;
int dp1[1<<18],dp2[1<<18];

int main()
{
    ios_base::sync_with_stdio(0);
    rub();
    cin>>n>>k;
    FOR(i,n)
    {
        string s;cin>>s;
        v.pb(st[s]);
        v1.pb(s);
    }
    FOR(i,k)
    {
        string s;cin>>s;
        w.pb(st[s]);
        w1.pb(s);
    }
    DBG(v);
    DBG(w);
    dp1[0]=0;
    dp2[0]=-1;
    FOR(i,1<<n)
    {
        int h=0;
        FOR(j,n) if ((1<<j)&i) h+=v[j];
        dp1[i]=h;
    }
    DBG(dp1[(1<<n)-1]);
    FOR(i,1<<n)
    {
        int best=-1;
        dp2[i]=-1;
        for(int k=i;;k=(k-1)&i)
        {
            
            if (dp1[i^k]==w[dp2[k]+1]) 
            {
                best=max(best,dp2[k]+1);
            }
            if (k==0) break;
        }
        dp2[i]=best;
    }
    if (dp2[(1<<n)-1]==k-1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    if (dp2[(1<<n)-1]==k-1)
    {
        int msk=(1<<n)-1;
        int nr=k-1;
        while(msk)
        {
            DBG(msk);
            DBG(nr);
            FOR(i,(1<<n))
            {
                if ((i&msk)!=i) continue;
                if (dp2[i]==nr-1 && dp1[i^msk]==w[nr])
                {
                    int x=i^msk;
                    vector<string> q;
                    FOR(j,n) if ((1<<j)&x) q.pb(v1[j]);
                    FOR(j,q.sz) 
                    {
                        cout<<q[j];
                        if (j!=q.sz-1) cout<<"+";
                    }
                    cout<<"->"<<w1[nr]<<endl;
                    nr--;
                    msk=i;
                    break;
                }
            }
        }
    }

    return 0;
}