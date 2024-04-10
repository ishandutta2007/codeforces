//  228

//Remember You used to think this was IMPOSSIBLE.
/*
                         __________
        Bring Me Thanos /         /
                       /_________/
                           |  |
                           |  |
                           |  |
                           |__|
        Mamba Forever-
                    o      |   __   |
                      \_ O |  |__|  |
                   ____/ \ |___WW___|
                   __/   /     ||
                               ||
                               ||
                _______________||________________
            _____
          ===///    , ,-. ,-   .-, , , ,-  ,_  ,  ,_ ,-
          --///    /_ |_/ _)  /""|/|/ |_] /=_ /_ /=_ _)
        ___///    __    __  __  ______  ____    ___
          ///  --/||  --// .'   //  "/ _//  )) (|  "/
      ---///   /' ||  _//.;  __//_.    //_="'  _\\
      --///- -/---||  //'||   //  ', _//  ;|     \\     ;
 ______/// __/_  _||_/<  `||_//__"/ _// --|\ /-._//    /
     _///      ,                        ---\\\       .'
  ___///_____"/                              `;=__.-'
 
 
 
        Steph Curry-
 
                 /|   o         o
                 \|=--            o
                    ##
                                    \\
                                 /   \O
                                O_/   T
                                T    /|
                                |\  | |
                 _______________|_|________
 
        Ironman 2025
                         __o      __o      o         __o        ,__o      o__,
             __ -_     _ \<_     -\<,    _/\_>     _`\<,_     _-\_<,      ,>_/-_
        ((( (_)T(_)   (_)/(_)   O / O   O,> / O   (*)/ (*)   (*)/'(*)    (*)`\(*)
                                        ___
                                       /___\
                                   .-.|=0-0=|.-.
                              (\_.'.-\ \_o_/`/-.'._/)
                          ~` - ~`-^_`~ -_~ ^- ~_` -~ _
                            -  ~  -  ^   - ~ -  ~  -
                                        ,////,
                                        /// 6|
                                        //  _|
                                       _/_,-'
                                  _.-/'/   \   ,/;,
                               ,-' /'  \_   \ / _/
                               `\ /     _/\  ` /
                                 |     /,  `\_/
                                 |     \'
                     /\_        /`      /\
                   /' /_``--.__/\  `,. /  \
                  |_/`  `-._     `\/  `\   `.
                            `-.__/'     `\   |
                                          `\  \
                                            `\ \
                                              \_\__
                                               \___)
 
 
 NO MATTER HOW HARD YOU WORK, I AM WILLING TO WORK HARDER THAN YOU............
 
 */
 
#include<iostream>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#include<math.h>
#include<time.h>
#include<queue>
#include<numeric>
#include<unordered_map>
#include<iomanip>
#include<stdio.h>
#include<stack>
#include<string>
#include<stdio.h>
#include<utility>
#include<iomanip>
#include<sstream>
#include<deque>
#include<initializer_list>
#include<unordered_set>
#include<list>
#include<bits/stdc++.h>

#define ll long long
#define fr(i,a,b) for(ll i = a;i<b;i++)
#define pie 3.14159265358979
#define pb push_back
//#define mp make_pair
#define fri(i,a,b) for(ll i = a;i>=b;i--)
#define pqll priority_queue<ll,vector<ll>,greater<ll>>
//#define pq priority_queue<ll>
#define pr pair<ll,ll>
#define prr pair<ll,pr>
#define f first
#define s second
#define pqr priority_queue<pair<ll,ll>>
//#define st stack
#define out(a) cout<<a<<"\n"

#define loop() for(;;)
#define frx(x,s) for(auto x: s)
#define read(v,n) for(int i = 0; i<n ; i++){cin>>v[i];}
#define read1(v,n) for(int i = 1; i<n ; i++){cin>>v[i];}
#define sortvec(ouas) sort(ouas.begin(),ouas.end())
#define outvec(v) for(int i = 0;i<v.size();i++){cout<<v[i]<<" ";}
#define sumvec(v,c) for(int i = 0;i<v.size();i++){c += v[i];}
#define sumarr(v,s) for(int i =1;i<v.size();i++){s[i] += s[i-1] + v[i];}
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define ld long double
#define pi 3.1415926536
#define div 1000003
#define mod 1000000007
#define MOD 998244353
#define N 10000005

const long long LL_INF = (long long) 2e18 + 5;
#define inf 1e18
using namespace std;
 
 
vector<ll> stone;

 
ll pow_of_10(ll x){
    ll result=1;
    fr(i,1,x+1){
        result *= 10;
    }
    return result;
}
 
ll c ;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

bool ispalin(string s){
    
    string t = s;
        reverse(s.begin(),s.end());
    if(s ==t ){
        return true;
    }
    return false;
}
ll yess(ll n , ll m , ll k , ll i , ll j){
    while(i <= n){
        cout<<m-j+1<<" ";
        while(j <= m){
            cout<<i<<" "<<j<<" ";
            j++;
        }
        cout<<"\n";
        j = 1;
        i++;
    }
    return 0;
}
ll power(ll base, ll exp, ll b){
    ll ans = 1;
    while(exp > 0){
        if(exp%2){
            ans *= base;
            ans%=b;
            
        }
        base *= base;
        base %= b;
        exp /= 2;
        
        // ans = base;
    }
    return ans;
}
/* Chill yr, its the experience that matters*/
/* Most people die rather than think.....just dont be like them ;) 
    IF YOU WANT THE BEST, FIRST YOU SHOULD BECOME ONE.
    
*/

  
// Utility function of Sieve of Sunda
//vector<bool> cubes(1e5+1,0);
const int MAX = 1e6 + 1;
bool prime[MAX + 1];

void sieve1() { //prime or not
	for (int i = 0; i <= MAX; i++) prime[i] = 1;

	prime[0] = prime[1] = 0;
    
	for (int i = 4; i <= MAX; i += 2) prime[i] = 0;

	for (int p = 3; p * p <= MAX; p += 2) {
		if (prime[p] == 1)
			for (int i = p * 2; i <= MAX; i += p) {
				prime[i] = 0;
			}
	}
}
       ll findSum(string str)
{
    ll n = str.length();
           ll x = 0;
    fri(i,n-1,0){
        x += (str[i]-'0');

    }
    return x;
}
ll power(ll base, ll exp){
    ll ans = 1;
    while(exp > 0){
        if(exp%2){
            ans *= base;
            ans%=mod;
            
        }
        base *= base;
        base %= mod;
        exp /= 2;
        
        // ans = base;
    }
    return ans%mod;
}
ll fact[1000006];
ll nCr(ll n, ll r){
    ll nn = fact[n]%mod;
    ll rr = power(fact[r],mod-2)%mod;
    ll rn = power(fact[n-r],mod-2)%mod;
    
    return (((nn*rr)%mod)*rn)%mod;
}

ll solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll i = 0;
    while(i < n-1){
        //trace3(i,s[i],s[i+1]);
        if(k == 0){
            break;
        }
        if(s[i] == '4' && s[i+1] == '7'){
            
            if(i%2 == 0){
                s[i] = '4';
                s[i+1] = '4';
                k--;
                if(k == 0){
                    break;
                }
            }
            else{
                s[i] = '7';
                s[i+1] = '7';
                k--;
                if(k == 0){
                    break;
                }
                if(i > 0 && s[i-1] == '4'){
                    if(k%2 != 0){
                        s[i-1] = '4';
                        s[i] = '4';
                        s[i+1] = '7';
                        
                        break;
                    }
                    else{
                        s[i-1] = '4';
                        s[i] = '7';
                        s[i+1] = '7';
                        break;
                    }
                }
            }
        }
        else{
            i++;
        }
    }
    cout<<s<<" ";
    return 0;
}
 /*
    4
    1 0    0 2
    0 2    1 0
    2 3    2 3
    3 1    3 1
 */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll flag= 0;
//     
 //  sieve1();
    
    // fr(i,1,9999){
    //     sq[i*i] = 1;
    // }
    if(flag){
        ll t ;
        cin>>t;
        while(t--){
            solve();
        }
 
    }
    else{
        solve();
    }
    return 0;
}
 
//5 3
//bat
//man
//cat
//pen
//map
//3
//?at
//ma?
//?a?
/*NO MATTER HOW HARD YOU WORK, I AM WILLING TO WORK HARDER THAN YOU............
                                                                        #KOBE BRYANT
 */
 
//insert
//traversal
//1
//(())
// crop prediction not classification
// crop disease detection not classification