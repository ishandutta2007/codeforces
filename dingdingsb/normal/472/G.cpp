#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f=1;ch=getc();}
		while(isdigit(ch)){t=t*10+ch-48;ch=getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
	char getC(){char c=getc();while(!isdigit(c)&&!isalpha(c)&&c!='('&&c!=')'&&c!='?')c=getc();return c;}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2=(1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
	void puts(char *str){int now=0;while(str[now]!=0)putc(str[now++]);putc('\n');}
}
typedef unsigned int u32;
typedef unsigned long long u64;


namespace Game {
	u64 p1[64][3200],p2[64][3200];
	inline void make(u64 arr[64][3200],int pos){
		int th=std::min(63,pos);
		for(int i=0;i<=th;i++)arr[i][(pos-i)>>6]|=1ull<<((pos-i)&63);
	}
	void solve(int n,int m,int q,char *s1,char *s2,int *qx,int *qy,int *qlen,u32 *ans){
		for(int i=0;i<n;i++)if(s1[i]-'0')make(p1,i);
		for(int i=0;i<m;i++)if(s2[i]-'0')make(p2,i);
		for(int i=0;i<q;i++){
			u32 res1=0,res2=0,res3=0,res4=0,res5=0,res6=0,res7=0,res8=0;
			int x=qx[i],y=qy[i],l=qlen[i];
			u32 block=l>>6,c;
			u64 *arr1=p1[x&63]+(x>>6);
			u64 *arr2=p2[y&63]+(y>>6);
			for(c=0;c+8<block;c+=8,arr1+=8,arr2+=8){
				#define popc __builtin_popcountll
				res1+=popc(arr1[0]^arr2[0]);
				res2+=popc(arr1[1]^arr2[1]);
				res3+=popc(arr1[2]^arr2[2]);
				res4+=popc(arr1[3]^arr2[3]);
				res5+=popc(arr1[4]^arr2[4]);
				res6+=popc(arr1[5]^arr2[5]);
				res7+=popc(arr1[6]^arr2[6]);
				res8+=popc(arr1[7]^arr2[7]);
			}
			int res=res1+res2+res3+res4+res5+res6+res7+res8;
			for(;c<block;c++,arr1++,arr2++)
				res+=popc(arr1[0]^arr2[0]);
			ans[i]=res+popc((arr1[0]^arr2[0])&((1ull<<(l&63))-1));
			out::write(ans[i]);out::putc('\n');
		}
	}
	void main() {
		char *s1=new char[200000+1];
		char *s2=new char[200000+1];
		int n,m;
		s1[n=0]=in::getC();while(isdigit(s1[n]))s1[++n]=in::getc();
		s2[m=0]=in::getC();while(isdigit(s2[m]))s2[++m]=in::getc();
		int q;
		in::read(q);
		u32 *anss=new u32[q];
		int *q_x=new int[q];
		int *q_y=new int[q];
		int *q_len=new int[q];
		for (int i=0;i<q;i++)
			in::read(q_x[i],q_y[i], q_len[i]);
		solve(n,m,q,s1,s2,q_x,q_y,q_len,anss);
	}
}
int main() {
	//freopen("my.out","w",stdout);
	Game::main();
	out::flush();
	return 0;
}