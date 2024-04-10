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
    int n;
    sc(n);
    int arr[4][4];
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)arr[i][j]=i*4+j;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		pr(arr[i%4][j%4]+16*(j/4)+(16*(n/4))*(i/4),"");
    	}
    	prl("");
    }
    return 0;
}