#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=1e5+5;
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

int n,a[maxn];
int main(){
//    judge();
	read(n);
	fortodo(i,1,n) read(a[i]);
	sort(a+1,a+1+n);
	long long now=0,ans=0;
	fortodo(i,1,n){
		if (now>(long long)a[i]) {ans++;continue;}
		now+=(long long)a[i];
	}
	cout<<(long long)((long long)(n)-ans);
    return 0;
}