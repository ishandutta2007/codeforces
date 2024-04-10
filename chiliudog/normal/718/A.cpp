#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
/*******************************head*******************************/
const int maxn=200005;
char s1[maxn],s2[maxn],s[maxn];
int n,t;
inline void add(char *s,int n){
    s[n]++;
    if(s[n]>'9'){
        per(i,n,1){
            if(s[i]>'9'){
                s[i]-=10;
                s[i-1]++;
            }else break;
        }
    }
}
int main(){
    read(n);read(t);
    scanf("%s",s+1);int pt=0;
    rep(i,1,n){if(s[i]=='.')pt=i;}
    rep(i,1,pt-1)s1[i]=s[i];int tot=0;
    rep(i,pt+1,n)s2[++tot]=s[i];int fi=tot;
    rep(i,1,tot){
        if(s2[i]>='5'){
            add(s2,i-1);t--;int j=i-1;fi=min(fi,i-1);
            while(t&&j){
                if(s2[j]>='5'){
                    add(s2,j-1);t--;j--;fi=min(fi,j);
                }else break;
            }
            break;
        }
    }if(s2[0])add(s1,pt-1);
    if(s1[0])putchar('1');
    printf("%s",s1+1);
    if(fi)putchar('.');
    rep(i,fi+1,tot)s2[i]=0;
    printf("%s",s2+1);
	return 0;
}