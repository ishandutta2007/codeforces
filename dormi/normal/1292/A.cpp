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
const int MAXN=1e5+1;
bool state[3][MAXN];
map<pii,set<pii>> bads;
int toch[3]={-1,0,1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    sc(n,q);
    int a,b;
    int cnt=0;
    rep(i,0,q){
        sc(a,b);
        state[a][b]=!state[a][b];
        if(state[a][b]){
            for(int j=0;j<3;j++){
                if(b+toch[j]>=1&&b+toch[j]<=n) {
                    if (state[max(1, (a + 1) % 3)][b + toch[j]]) {
                        bads[{a, b}].insert({max(1, (a + 1) % 3), b + toch[j]});
                        cnt++;
                        bads[{max(1, (a + 1) % 3), b + toch[j]}].insert({a, b});
                        cnt++;
                    }
                }
            }
        }
        else{
            for(auto x:bads[{a,b}]){
                bads[x].erase({a,b});
                cnt-=1;
            }
            cnt-=(int)bads[{a,b}].size();
            bads[{a,b}].clear();
        }
        if(cnt)prl("No");
        else prl("Yes");
    }
    return 0;
}