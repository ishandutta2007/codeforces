#include <bits/stdc++.h>
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
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    sc(s);
    char best='z'+1;
    for(char x:s){
		if(x<=best)prl("Mike");
		else prl("Ann");
		best=min(x,best);
    }
    return 0;
}