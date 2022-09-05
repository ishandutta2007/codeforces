#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1020000;
int n,k,buc[27],rev[27];
char s[N],a[N],b[N],t[N];bool gg;
void calc(int p){
	if(buc[s[p]-'a']>=0)gg|=buc[s[p]-'a']!=t[p];
	else {if(rev[t[p]-'a']>=0){gg=1;return;}buc[s[p]-'a']=t[p];rev[t[p]-'a']=s[p];}
}
void getmax(int i){
	for(;i<=n;i++){
		if(buc[s[i]-'a']>=0)t[i]=buc[s[i]-'a'];
		else{
			per(j,k-1,0)if(rev[j]<0){t[i]='a'+j,calc(i);break;}
		}
	}
}
void getmin(int i){
	for(;i<=n;i++){
		if(buc[s[i]-'a']>=0)t[i]=buc[s[i]-'a'];
		else{
			rep(j,0,k-1)if(rev[j]<0){t[i]='a'+j,calc(i);break;}
		}
	}
}
bool ck(){
	rep(i,1,n)if(t[i]!=a[i]){
		if(t[i]<a[i])return 0;break;
	}
	rep(i,1,n)if(t[i]!=b[i]){
		if(t[i]>b[i])return 0;break;
	}
	return 1;
}
int main() {
	int T;read(T);
	while(T--){
		read(k);scanf("%s%s%s",s+1,a+1,b+1);n=strlen(s+1);
		memset(buc,-1,sizeof(buc));memset(rev,-1,sizeof(rev));
		int p=1;gg=0;
		while(p<=n&&a[p]==b[p]){
			t[p]=a[p];calc(p);//if(buc[s[p]-'a']>=0)gg|=buc[s[p]-'a']!=t[p]-'a';
			p++;
		}
		if(p<=n&&!gg){
			/*if(b[p]-a[p]>1){
				t[p]=a[p]+1;calc(p);//buc[s[p]-'a']=t[p]-'a';
				if(!gg)getmax(p+1);
			}*/
			bool fd=0;
			rep(i,a[p]+1,b[p]-1){//-->fd
				gg=0;t[p]=i;calc(p);
				if(gg){gg=0;t[p]=0;}
				else{fd=1;getmax(p+1);break;}
			}
			if(!fd){
				int tmp[27],tmp1[27];memcpy(tmp,buc,sizeof(buc));memcpy(tmp1,rev,sizeof(rev));
				gg=0;t[p]=a[p];calc(p);getmax(p+1);
				//printf("<%d>",gg);
				if(gg||!ck()){
					memcpy(buc,tmp,sizeof(tmp));memcpy(rev,tmp1,sizeof(tmp1));
					gg=0;t[p]=b[p];calc(p);getmin(p+1);
				}
			}
		}
		if(!gg&&!ck())gg=1;
		if(gg)puts("NO");
		else{
			puts("YES");
			rep(i,0,k-1)if(buc[i]<0)rep(j,0,k-1)if(rev[j]<0){
				buc[i]='a'+j;rev[j]='a'+i;break;
			}
			rep(i,0,k-1)assert(buc[i]>='a'&&buc[i]<='a'+k-1);
			rep(i,0,k-1)printf("%c",buc[i]);puts("");
		}
	}
	return 0;
}