#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define read(a) scanf("%d",&a)
#define write(a) printf("%d",a)
const int O=60,o=300,inf=1e9;
char s[o],len;int f[2][O][o][o],ans=inf;
inline void swap(char&x,char&y){char t=x;x=y;y=t;}
inline int min(int a,int b){return a<b?a:b;}
int main(){
	scanf("%s",s+1);len=strlen(s+1);
	for(int i=1;i*2<=len;++i) swap(s[i],s[len-i+1]);
	s[++len]='0';for(int carry=0;carry<O;++carry) for(int cp=0;cp<o;++cp) for(int cn=0;cn<o;++cn) f[0][carry][cp][cn]=inf;f[0][30][o-1][o-1]=0;
	for(int i=1;i<=len;++i){
		for(int carry=0;carry<O;++carry) for(int cp=0;cp<o;++cp) for(int cn=0;cn<o;++cn) f[1][carry][cp][cn]=inf;
		for(int carry=0,val,nw,nxt;carry<O;++carry) for(int cp=o-1;cp+1;--cp) for(int cn=o-1;cn+1;--cn) if(f[0][carry][cp][cn]^inf){
			if(cp) f[0][carry][cp-1][cn]=min(f[0][carry][cp-1][cn],f[0][carry][cp][cn]);//optimize by getting the suffix min
			if(cn) f[0][carry][cp][cn-1]=min(f[0][carry][cp][cn-1],f[0][carry][cp][cn]);
			carry-=30;nxt=(val=carry+cp-cn)/10;nw=val%10;if(nw<0) nw+=10;if(val<0&&nw) --nxt;nxt+=30;carry+=30;
			if(nxt<0||nxt>=O) continue;
			if(nw==s[i]-48) f[1][nxt][cp][cn]=min(f[1][nxt][cp][cn],f[0][carry][cp][cn]+cp+cn);
		}
		for(int carry=0;carry<O;++carry) for(int cp=0;cp<o;++cp) for(int cn=0;cn<o;++cn) f[0][carry][cp][cn]=f[1][carry][cp][cn];
	}
	for(int cp=0;cp<o;++cp) for(int cn=0;cn<o;++cn) ans=min(ans,f[0][30][cp][cn]);
	write(ans);
	return 0;
}