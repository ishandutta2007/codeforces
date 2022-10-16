//  228

#include <bits/stdc++.h>
using namespace std;
#define cp                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);					  \
    cout<<fixed;

#define test \
    int text_cases;        \
    cin >> text_cases;  		\
    while (text_cases--)

#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define popb pop_back


#define ll long long int
#define pairii pair<int,int>
#define vecii vector<int>
#define vecll vector<ll>
#define pairll pair<ll,ll>

#define INF (int)(1e9)
#define MOD (ll)(1e9+7)
//#define MOD 998244353
#define PI 3.1415926536

template<typename T> vector<T>& operator-- (vector<T> &v){for (auto& i : v) --i; return  v;}
template<typename T> vector<T>& operator++ (vector<T> &v){for (auto& i : v) ++i; return  v;}
template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename Y> istream& operator>>(istream& is,  pair<T,Y> &p){ is >> p.first >> p.second; return is;}
template<typename T, typename Y> ostream& operator<<(ostream& os,  pair<T,Y>  p){ os << p.first << ' ' << p.second  << ' '; return os;}

#define fr(i,a,n) for(int i=a;i<n;i++)
#define sz(x) (ll)(x).size();
#define lCase(a) transform(a.begin(),a.end(),a.begin(),::tolower)
#define uCase(a) transform(a.begin(),a.end(),a.begin(),::toupper)

/*Important ASCII CODES
 * 0=48
 * a=97
 * A=65
 * {=123
 * [=91
 * <=60
 * +=43
 */

int gcd(int x, int y){
    if(y==0)
    return x;
    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

ll gcd(ll x, ll y){
    if(y==0)
    return x;
    return gcd(y,x%y);
}
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}

void swap(ll&x,ll&y){
	ll temp=x;
	x=y;
	y=temp;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll binpowM(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll factM(int n){
	ll a=1;
	for(int i=1;i<=n;i++){
		a=(a*i)%MOD;
	}
	return a;
}
//FOR PRIME

//map <int,int> primes;
//vecii pr(INF+1,0);
//void sieve_prime(){
	//pr[1]=1;
	//pr[0]=1;
    //for(int i=2;i*i<INF;i++){
        //if(pr[i]==0){
            ////primes[i]=1;
            //for(int j=i*i;j<INF;j+=i){
                //pr[j]=i;
            //}
        //}
    //}
//}

//FOR FACTORIAL

//vectorll fact;
//vectorll inv;
//void factorial()
//{
	//ll i;
	//fact.pb(1);
	//inv.pb(binpow(fact[0], MOD - 2));
	//for (i = 1; i <= INF; i++)
	//{
		//fact.pb((i * fact[i - 1]) % MOD);
		//inv.pb(binpow(fact[i], MOD - 2));
	//}
//}

//int binarySearch(vector<ll>&arr, int l, int r, ll x) 
//{ 
    //while (l <= r) { 
        //int m = l + (r - l) / 2; 
  
        //// Check if x is present at mid 
        //if (arr[m] == x) 
            //return m; 
  
        //// If x greater, ignore left half 
        //if (arr[m] < x) 
            //l = m + 1; 
  
        //// If x is smaller, ignore right half 
        //else
            //r = m - 1; 
    //} 
  
    //// if we reach here, then element was 
    //// not present 
    //return -1; 
//} 

//To erase consecutive same char
// string.erase(unique(s.begin(),s.end()),s.end());

void solve(){
	ll n,f=0,s=0;
	//cin>>n;
	string a;
	cin>>a;
	n=a.length();
	fr(i,0,n){
		if(a[i]=='4')
		f++;
		else if(a[i]=='7')
		s++;
	}
	if(f==0&&s==0){
		cout<<-1<<endl;
	}
	else if(s>f)
	cout<<7<<endl;
	else
	cout<<4<<endl;
	
}

int main()
{
    cp
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	//test
	//int ttest;
	//cin>>ttest;
	//fr(i,0,ttest)
	solve();
	return 0;
	
}