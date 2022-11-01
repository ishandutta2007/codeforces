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
const int maxn=100005;
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
int m;
int main(){
    read(m);
    if(m==0){
    	puts("4\n1 2 3 4");return 0;
    }
    int sum=0,last=5;
    while(sum<m){
    	int j=last;
    	while(j%5==0){
    		sum++;j/=5;
    	}
    	last+=5;
    }
    if(sum>m){
    	puts("0");return 0;
    }
    puts("5");
    printf("%d %d %d %d %d\n",last-5,last-4,last-3,last-2,last-1);
    return 0;
}