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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    sc(n,k);
    string a;
    sc(a);
	if(n==1&&k){
		prl("0");
		return 0;
	}
    for(int i=0;k>0&&i<n;i++){
    	if(i==0){
    		if(a[i]>'1'&&k)a[i]='1',k--;
    	}
    	else{
    		if(a[i]>'0'&&k)a[i]='0',k--;
    	}
    }
    prl(a);
    return 0;
}