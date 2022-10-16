//  228

/**                        
                          
                           
                     
                       
                           
                                           
                                       
                                           
                                  
                                  
                                     
                                                  
                                                  
                                                      
                                                    
                                                  
                                                   
                                                * * * * * * * * * * * * * * * *  *
                                                *       Date  :- 03-03-2021      *
                                                * * * * * * * * * * * * * * * *  *

**/
#include <bits/stdc++.h>

#define     fr              freopen("input.txt","r",stdin)
#define     fw              freopen("output.txt","w",stdout)
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


#define     ll              long long int
#define     ld              long double
#define     ul              unsigned long long int
#define     dl              double
#define     st              string

#define     vb              vector<bool>
#define     vll             vector <ll>
#define     lll             list <ll>
#define     ls              list<string>
#define     lc              list <char>
#define     qll             queue <ll>
#define     stll            stack <ll>
#define     sll             set <ll>
#define     sts             set <string>
#define     vs              vector <string>
#define     pll             pair <ll,ll>
#define     mll             map <ll,ll>
#define     msl             map <string,ll>
#define     vecp            vector < pair <ll, ll> >
#define     vecpp           vector < pair <ll, pair <ll, ll> > >
#define     pb              push_back
#define     MP              make_pair
#define     pf              push_front
#define     in              insert
#define     eb              emplace_back
#define     ppb             pop_back
#define     ppf             pop_front

#define     el              endl
#define     rt              return 0

#define     F               first
#define     S               second
#define     N               printf("NO\n")
#define     Y               printf("YES\n")
#define     pr(a)           printf("%lld\n",a)
#define     prs(a)          printf("%lld ",a)
#define     prc(a)          printf("Case %lld: ",a)
#define     sf1(a)          scanf("%lld",&a)
#define     sf2(a,b)        scanf("%lld%lld",&a,&b)
#define     sf3(a,b,c)      scanf("%lld%lld%lld",&a,&b,&c)


#define     gcd(a, b)       __gcd(a, b)
#define     lcm(a, b)       (a * b) / gcd(a, b)
#define     len(X)          ((ll)X.size())


#define     sim                 template<class T
#define     wh                  while
#define     rep(i, l, r)        for(long long i = l; i<r; i++)
#define     repi(i, l, r, p)    for(long long i = l; i<r; i+=p)
#define     repi2(i, l, r, p)   for(long long i = l; i>=r; i+=p)
#define     repb(i, r, l)       for(long long i = r; i>=l; i--)
#define     repbd(i, r, l, d)   for(long long i = r; i>l; i-=d)
#define     repr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end))) ///traverse a array!!

#define     max3(a, b, c)       max(a, max(b, c))
#define     min3(a, b, c)       min(a, min(b, c))
#define     max4(a, b, c, d)    max(max(a, b), max(c, d))
#define     min4(a, b, c, d)    min(min(a, b), min(c, d))

#define     vsort(v)            sort(v.begin(),v.end())
#define     all(container)      container.begin(), container.end()
#define     rall(container)     container.rbegin(), container.rend()
#define     iterate(v, it)      for(vector< long long >::const_iterator it = v.begin(); it != v.end(); it++)

#define     rand(V)             random_shuffle(all(V))
#define     lb(a,X)             lower_bound(all(a),X)-a.begin()
#define     ub(a,X)             upper_bound(all(a),X)-a.begin()

#define     BIG                 300000
#define     mem(a,v)            memset(a,v,sizeof(a))
#define     F               first
#define     S               second
#define     for0(i,n)       for(int (i)=0; (i) < (n); (i)++)


using namespace std;
string v2s(vll &A){ll Z=len(A);string S(Z,' ');rep(i,0,Z)S[i]=A[i]+'0';return S;}

const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1.0);

#define deb(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }

vector<pair<ll, ll> > A;
bool cmp(pair<ll, ll>& a,pair<ll, ll>& b){return a.second < b.second;}
void sort(map<ll, ll>& M){for (auto& it : M) {A.push_back(it);}sort(A.begin(), A.end(), cmp);}



ll powMod(ll x, ll y)
{
     ll res = 1;
     while(y>0)
     {
         if(y & 1) res=(res*x)%MOD;
         x = (x*x)%MOD;
         y>>=1;
     }
     return res;
}
ll stringdigitsum(string digits){ll num,total=0; for(int i = 0; i < digits.length(); i++){num = digits.at(i) - '0';assert(0 <= num && num <= 9);total += num;}return total;}


int main()
{

     ll a,b,i,c,d,e,g,r,j,k=0,l,f=1,h=0,tttt=0,o=0,q,t,x,p,u,n,m=0,z,y,cnt;
     string s,s2;
     char cc,cc1;
//     sf1(tttt);
//     while(tttt--)
//     {
//
//
//     }
        cin>>a>>b;
        cnt=0;
        vecp v;
        rep(i,0,b)
        {
            cin>>c>>d;
            v.pb({d,c});
        }
        sort(v.rbegin(),v.rend());
        for(auto i : v)
        {
            if(a<=0) break;
            if(a-i.S>=0)
            {
                a-=i.S;
                cnt+=i.S*i.F;
            }
            else
            {
                cnt+=a*i.F;break;
            }
        }
        cout<<cnt<<endl;




 rt;
}