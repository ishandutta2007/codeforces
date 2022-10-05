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

const int N=1005;
ll X,Y,x,y;
char s[N];
int n,m;

int main(){
    read(n),read(m);
    rep(i,1,n){
        scanf("%s",s+1);
        rep(j,1,m)
            if(s[j]=='B'){
                X+=i,x++;
                Y+=j,y++;
            }
    }
    cout<<X/x<<" "<<Y/y<<endl;
    return 0;
}