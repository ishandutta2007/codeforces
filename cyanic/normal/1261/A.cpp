#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
    int f=0;x=0;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    if(f)x=-x;
}

const int N=10005;
int a[N],aim[N];
char s[N];
int n,K;

void rmain(){
    read(n),read(K);
    scanf("%s",s+1);
    rep(i,1,n){
        if(s[i]=='('){
            a[i]=1;
        }
        else{
            a[i]=-1;
        }
    }
    rep(i,1,K-1){
        aim[i*2-1]=1;
        aim[i*2]=-1;
    }
    int rem=(n-2*(K-1))/2;
    rep(i,n-rem-rem+1,n-rem){
        aim[i]=1;
        aim[i+rem]=-1;
    }
    vector<pii> ans;
    rep(i,1,n){
        if(a[i]==aim[i]){
            continue;
        }
        int k=i;
        for(;a[k]!=aim[i];k++);
        reverse(a+i,a+k+1);
        ans.pb(mp(i,k));
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.fi<<" "<<x.se<<endl;
    }
}

int main(){
    int T;
    read(T);
    while(T--)rmain();

    return 0;
}