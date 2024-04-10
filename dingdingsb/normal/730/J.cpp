#include <bits/stdc++.h>
using namespace std;
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
int n;
struct node{
    int a,b;
    bool operator<(const node c)const{
        return b>c.b;
    }
}p[110];
int suma,sumb;
int f[10000+10][110];
int main(){
    in::read(n);
    for(int i=1;i<=n;i++)
        in::read(p[i].a),suma+=p[i].a;
    for(int i=1;i<=n;i++)
        in::read(p[i].b);
    sort(p+1,p+1+n);
    int k;
    for(k=1;k<=n;k++){
        sumb+=p[k].b;
        if(sumb>=suma){out::write(k),out::putc(' ');break;}
    }
    memset(f,128,sizeof f);f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=sumb;j>=p[i].b;j--)
			for(int kk=1;kk<=k;kk++){
				f[j][kk]=max(f[j][kk],f[j-p[i].b][kk-1]+p[i].a);
			}
    int ans=-0x3f3f3f3f;
	for(int i=suma;i<=sumb;i++)ans=max(ans,f[i][k]);
	out::write(suma-ans);
    out::flush();
}