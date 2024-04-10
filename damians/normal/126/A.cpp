    #include <string>

    #include <vector>

    #include <algorithm>

    #include <cmath>

    #include <set>

    #include <queue>

    #include <map>

    #include <cstdio>

    #include <iomanip>

    #include <sstream>

    #include <iostream>

    #include <cstring>

    #define REP(i,x,v)for(int i=x;i<=v;i++)

    #define REPD(i,x,v)for(int i=x;i>=v;i--)

    #define FOR(i,v)for(int i=0;i<v;i++)

    #define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

    #define REMIN(x,y) (x)=min((x),(y))

    #define REMAX(x,y) (x)=max((x),(y))

    #define pb push_back

    #define sz size()

    #define mp make_pair

    #define fi first

    #define se second

    #define ll long long

    #define IN(x,y) ((y).find((x))!=(y).end())

    #define LOLDBG

    #ifdef LOLDBG

    #define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;

    #define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;

    #else

    #define DBG(vari)

    #define DBG2(v1,v2)

    #endif

    #define CZ(x) scanf("%d",&(x));

    #define CZ2(x,y) scanf("%d%d",&(x),&(y));

    #define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));

    #define ALL(x) (x).begin(),(x).end()

    #define tests int dsdsf;cin>>dsdsf;while(dsdsf--)

    #define testss int dsdsf;CZ(dsdsf);while(dsdsf--)

    using namespace std;

    typedef pair<int,int> pii;

    typedef vector<int> vi;

    template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}

    template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }







    int main()

    {

        ios_base::sync_with_stdio(0);
        ll t1,t2,t0,x1,x2;
        cin>>t1>>t2>>x1>>x2>>t0;
        t1-=t0;
        t2-=t0;

        if (t1==0 && t2==0)
        {
            cout<<x1<<" "<<x2;
            return 0;
        }
        else if (t1==0 && t2>0)
        {
            cout<<x1<<" "<<0;
            return 0;
        }
        else if (t1<0 && t2>0)
        {
            t1=abs(t1);
            //DBG(t1);
            //DBG(t2);
           
            ll b=10000000000000LL,b1=0,b2=1;
            //swap(x1,x2);
            //swap(t1,t2);
            REP(i,1,x2)
            {
                //DBG(i);
                //DBG(b);
                ll g=i*t2;
                //if (i==76) DBG(g%t2);
                //DBG(g);
                //DBG(g%t2);
                ll n1=g/t1;
                if (n1>x1) n1=x1;
                ll n2=i;
                //DBG(i);
                //DBG((t2*n2-t1*n1)*1.0/(n1+n2));
                //if ((t2*n2-t1*n1)*1.0/(n1+n2)<=(t2*b2-t1*b1)*1.0/(b1+b2))
                if ((n1+n2)*(-b1*t1+b2*t2)>=(b1+b2)*(-n1*t1+n2*t2))
                {
                    if ((n1+n2)*(-b1*t1+b2*t2)>(b1+b2)*(-n1*t1+n2*t2))
                    //if ((t2*n2-t1*n1)*1.0/(n1+n2)<(t2*b2-t1*b1)*1.0/(b1+b2))
                    {
                        b1=n1;
                        b2=n2;
                    }
                    else if (b1+b2<n1+n2)
                    {
                        b1=n1;
                        b2=n2;
                    }
                }

            }
            cout<<b1<<" "<<b2;
            return 0;
        }
        else
        {
            cout<<0<<" "<<x2;
        }
       

       

        return 0;

    }