#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b);
#define w1 first
#define w2 second
typedef pair<int,int> pin;
inline void read(int64 &x){
	x=0;int64 f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int64 sum,n;
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main(){
	read(n);
	if(n%2!=0){
		puts("0");return 0;
	}
	n/=2;
	if(n%2==0)
		cout<<n/2-1;
	else
		cout<<n/2;
    return 0;
}