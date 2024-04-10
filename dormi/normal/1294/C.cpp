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
        int a;
        sc(a);
        vector<int> touse;
        for(int i=2;i<=sqrt(a);i++){
            while(a%i==0){
                touse.push_back(i);
                a/=i;
            }
        }
        if(a>1)touse.push_back(a);
        int first=touse[0];
        if(sz(touse)>=2){
            int second;
            int loc;
            if(touse[1]==first){
                if(sz(touse)>=3){
                    second=touse[1]*touse[2];
                    loc=3;
                }
                else{
                    prl("NO");
                    continue;
                }
            }
            else{
              second=touse[1];
              loc=2;
            }
            int fin=1;
            for(int i=loc;i<sz(touse);i++){
                fin*=touse[i];
            }
            if(fin==1||fin==second||fin==first){
                prl("NO");
            }
            else{
                prl("YES");
                prl(first,second,fin);
            }
        }
        else prl("NO");
    }
    return 0;
}