#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
int T,n,k;
string s;
map<char,int>cnt;
void solve(){
    cin>>n>>k;
    cin>>s;
    int t=n/k;
    cnt.clear();
    for(auto ch:s)cnt[ch]++;

    string res="";

    while(cnt['a'] && k){
        char cur='a';
        rep(x,'a','z'){
            if(cnt[x] && x<='a'+t-1)cnt[x]--;
            else{
                cur=x;
                break;
            }
        }
        res+=cur;
        k--;
    }

    while(k--)res+="a";
    cout<<res<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}