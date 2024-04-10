#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=10005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
bool flag[maxn];
int main(){
 //   judge();
    int a,b,c;
    read(a);read(b);read(c);
    flag[0]=1;
    rep(i,1,c){
    	if(i-a>=0)flag[i]|=flag[i-a];
    	if(i-b>=0)flag[i]|=flag[i-b];
    }
    if(flag[c])
    	puts("Yes");
    else
    	puts("No");
    return 0;
}