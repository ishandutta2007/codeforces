#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
#define int long long
const int mod=1e9+7;
using namespace std;
bool mxydy[2100],mdy[2100];
int n,x,pos;
template<class T>T ksm(T a,T b,T c){
    T res=1;
    while(b){
        if(b&1)res=res*a%c;
        a=a*a%c;b>>=1;
    }return res;
}
int A(int n,int m){
	if(m>n)return 0; 
	int res=1;
	for(int i=1;i<=m;i++)
		(res*=(n-i+1))%=mod;
	return res;
}
signed main(){
	in::read(n,x,pos);//x++;
	int left=0,right=n;
	while(left<right){
		int mid=left+right>>1;
		if(pos<mid){
			right=mid;
			mdy[mid]=1;
			//printf("%d \n",mid);
		}else{
			left=mid+1;
			mxydy[mid]=1;
			//printf("%d \n",mid);
		}
	}
	int xydy=0,dy=0;
	for(int i=0;i<n;i++)
		xydy+=mxydy[i],
		dy+=mdy[i];
	if(mxydy[pos])xydy--;
	//printf("%d %d\n",xydy,dy);
	out::write(A(x-1,xydy)*A(n-x,dy)%mod*A(n-xydy-dy-1,n-xydy-dy-1)%mod);
	out::flush();
	return 0;
}