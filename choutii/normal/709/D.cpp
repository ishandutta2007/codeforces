#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<complex>
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
#define inf 1001001001
#define infll 1001001001001001001LL
#define ll long long
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define Ri register int
#define gc getchar()
#define il inline
il int read(){
	bool f=true;ll x=0;char ch;while(!isdigit(ch=gc))if(ch=='-')f=false;while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=gc;}return f?x:-x;
}
#define gi read()
#define FO(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
int check(ll x){
    int l=1,r=1000005;
    if(!x)	return 0;
    while(l<=r){
        int mid=(l+r)>>1;
        if((ll)mid*(mid-1)<(ll)2*x)
			l=mid+1;
        else 
			r=mid-1;
    }
    return l;
} 
 
int main(){
    ll a,b,c,d;
 	a=gi;b=gi;c=gi;d=gi;
    ll x=check(a),y=check(d);
    if(!x&&(b||c))x=1;
    if(!y&&(b||c))y=1;
    if(x*(x-1)!=2*a||y*(y-1)!=2*d||x*y!=b+c)cout<<"Impossible\n";
    else{
        if(!x&&!y)printf("0");
        else if(!x)
            for(int i=1;i<=y;i++)printf("1");
        else if(!y)
            for(int i=1;i<=x;i++)printf("0");
	    else{
	        int t=b/y,f=y-b%y;
	        for(int i=1;i<=t;i++)printf("0"),x--;
	        for(int i=1;i<=f;i++)printf("1"),y--;
	        if(x>0){printf("0");x--;}
	        for(int i=1;i<=y;i++)printf("1");
	        for(int i=1;i<=x;i++)printf("0");
	    }
    }
    return 0;
}