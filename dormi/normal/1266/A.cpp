#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    rep(i,0,n){
		string a;
		sc(a);
		bool w[3]={false,false,false};
		int sum=0;
		for(char x:a){
			sum+=(x-'0');
			if(w[2]&&x=='0')w[0]=true;
			if(x=='0')w[2]=true;
			if(x>'0'&&(x-'0')%2==0)w[0]=true;
		}
		if(sum%3==0)w[1]=true;
		if(w[0]&&w[1]&&w[2])prl("red");
		else prl("cyan");
    }
    return 0;
}