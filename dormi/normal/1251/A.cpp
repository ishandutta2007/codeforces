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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    sc(t);
    while(t--){
    	string a;
    	sc(a);
    	bool work[26]={};
    	char last='$';
    	int am=0;
    	for(char x:a){
    		if(x!=last){
    			if(am%2)work[last-'a']=true;
    			am=0;
    			last=x;
    		}
    		am++;
    	}
    	if(am%2)work[last-'a']=true;
    	rep(i,0,26)if(work[i])pr((char)('a'+i));
    	prl("");
    }
    return 0;
}