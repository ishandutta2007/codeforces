#include<bits/stdc++.h>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=1e6+10;

int n,m;

char s[N];

vector <int> G[N/4];
int fa[N/4],ch[N/4];

map <string,int> M;
int kc;

int ans;
int val[N/4],cnt;


int sum[210][N/4],Inl[N];


int dfs(int u,int d){
	int mi=cnt+1;
	rep(i,0,G[u].size()-1) mi=min(mi,dfs(G[u][i],d+(ch[u]==val[d+1])));
	if(d>=cnt-1 && val[cnt]==ch[u]) ans++;
	//if(u==4) cout<<"#"<<d<<' '<<mi<<endl;
	//if(Inl[ch[u]]) {
		//if(sum[d+1][ch[u]]-sum[mi-2][ch[u]]>0) ans++,cout<<"FindAns u="<<u<<endl;
	//}
	if(mi>1 && ch[u]==val[mi-1]) mi--;
	return mi;
}













int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	int now=0;
	rep(i,1,len) {
		int j=i;
		while(s[j]!='>') j++;
		string t;
		rep(k,i+1+(s[i+1]=='/'),j-1-(s[j-1]=='/')) t+=s[k];
		//cout<<i<<' '<<j<<' '<<"name= "<<t<<endl;
		int num;
		if(M.count(t)) num=M[t];
		else num=M[t]=++kc;
		if(s[i+1]=='/') now=fa[now];
		else if(s[j-1]=='/') {
			G[now].push_back(++n);
			fa[n]=now;
			//cout<<"Add Edge"<<now<<' '<<n<<endl;
			ch[n]=num;
		} else {
			G[now].push_back(++n);
			fa[n]=now;
			//cout<<"Add Edge"<<now<<' '<<n<<endl;
			ch[n]=num;
			ch[now=n]=num;
		}
		i=j;
	}
	rep(ttt,1,m=rd()) {
		gets(s);
		len=strlen(s);
		string t;
		s[len]=' ';
		int fl=1;
		cnt=0;
		rep(i,0,len) {
			if(s[i]!=' ') t+=s[i];
			else {
				if(!M.count(t)) {
					fl=0;
					break;
				}
				int num=M[t];
				val[++cnt]=num;
				t.clear();
			}
		}
		if(!fl) {
			puts("0");
			continue;
		}
		rep(i,1,cnt) Inl[val[i]]=1;
		rep(i,1,cnt) {
			rep(j,1,cnt) sum[i][val[j]]=sum[i-1][val[j]];
			sum[i][val[i]]++;
		}
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
		rep(i,1,cnt) Inl[val[i]]=0;
	}
}