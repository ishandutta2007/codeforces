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
const int MAXN=30;
int T;
int bucket[MAXN];
char ch;
int cnt[5];
void solve(){
    memset(bucket,0,sizeof bucket);
    memset(cnt,0,sizeof cnt);
    rep(i,1,4){
        cin>>ch;
        bucket[ch-'a']++;
    }
    rep(i,0,25)if(bucket[i])cnt[bucket[i]]++;
    if(cnt[4]){
        cout<<"0\n";
    }else if(cnt[3] || cnt[2]==2){
        cout<<"1\n";
    }else if(cnt[2]){
        cout<<"2\n";
    }else{
        cout<<"3\n";
    }
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}