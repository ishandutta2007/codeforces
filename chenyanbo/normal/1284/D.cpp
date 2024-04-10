#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
#define REP(i, n) for(int i = 0;i < (n);i++)
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
//const int mod=1000000007 ;
const llint inf=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-10;
template <class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
void sfl(bitset<128>&in){
	in^=(in<<13);
	in^=(in>>17);
	in^=(in<<5);
}
int main(void){
	cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);
	int i,j,n;cin>>n;
	vector<pair<int,int>>Aiv(n+n);
	vector<pair<int,int>>Biv(n+n);
	REP(i,n){
		int q,w,e,r;cin>>q>>w>>e>>r;
		Aiv[i*2]=mp(q,i);Aiv[i*2+1]=mp(w,i+n);
		Biv[i*2]=mp(e,i);Biv[i*2+1]=mp(r,i+n);
	}
	SO(Aiv);SO(Biv);
	vector<pair<int,int>>A(n+n);
	vector<pair<int,int>>B(n+n);
	int mae=0,gen=0;
	//hash with XOR
	vector<bitset<128>>myha(n);
	REP(i,n){
		myha[i]=1812433253LL *(i+101)*(i+5)+27;myha[i]<<30;
		REP(j,30){sfl(myha[i]);}
	}
	vector<bitset<128>>Aha(n);
	vector<bitset<128>>Bha(n);
	bitset<128> Awa=0,Agen=0,Bwa=0,Bgen=0;
	REP(i,n+n){
		int t=Aiv[i].sec;
		if(t<n){
			Awa^=myha[t];
			Agen^=myha[t];
			Aha[t]=Agen^Awa;
		}else{
			t-=n;
			Agen^=myha[t];
			Aha[t]^=Awa;
		}
	}
	REP(i,n+n){
		int t=Biv[i].sec;
		if(t<n){
			Bwa^=myha[t];
			Bgen^=myha[t];
			Bha[t]=Bgen^Bwa;
		}else{
			t-=n;
			Bgen^=myha[t];
			Bha[t]^=Bwa;
		}
	}
	cout<<(Aha==Bha?"YES":"NO")<<endl;
	
	return 0;
}