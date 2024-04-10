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
    string a;
    sc(n,a);
    int ocnt=0,zcnt=0;
    for(char x:a){
    	if(x=='z')zcnt++;
    	else if(x=='n')ocnt++;
    } 
    for(int i=0;i<ocnt;i++)pr("1 ");
	for(int i=0;i<zcnt;i++)pr("0 ");
    return 0;
}