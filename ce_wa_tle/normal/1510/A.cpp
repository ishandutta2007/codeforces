#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
typedef long long ll;typedef long double ld;const ll N=10000;typedef ll aN[N];
aN head,next,to,num,z,h,w;ll cnt=0,ts,tn,tc,tz;char ans[1222][1222],s[1222][1222],c[N],t[N];
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}int qmax(ll&u,ll v){return u<v?u=v,1:0;}
void line(ll x,ll l,ll r,ll w){ans[x][l]=ans[x][r]='+';if(w<=0)memset(ans[x]+l+1,'-',r-l-1);
else ans[x][l+1]='-',ans[x][l+2]='>',memset(ans[x]+l+w+3,'-',r-l-w-3);if(!~w)ans[x][l+1]='<';if(w>=0)ans[x][r-1]='>';}
void dfs(ll x,ll y,ll u){switch(z[u]){
		case'+':{ll v=to[head[u]];dfs(x,y+3,v),h[u]=h[v]+2,w[u]=w[v]+6;ll l=y,r=y+w[u]-1;
		rep(i,x+2,x+h[v])ans[i][l]=ans[i][r]='|';line(x+1,l,r,w[v]),line(x+h[v]+1,l,r,-1);}break;
		case'?':{ll v=to[head[u]];dfs(x+3,y+3,v),h[u]=h[v]+3,w[u]=w[v]+6;ll l=y,r=y+w[u]-1;
		rep(i,x+2,x+3)ans[i][l]=ans[i][r]='|';line(x+1,l,r,0),line(x+4,l,r,w[v]);}break;
		case'*':{ll v=to[head[u]];dfs(x+3,y+3,v),h[u]=h[v]+5,w[u]=w[v]+6;ll l=y,r=y+w[u]-1;
		rep(i,x+2,x+h[v]+3)ans[i][l]=ans[i][r]='|';line(x+1,l,r,0),line(x+4,l,r,w[v]),line(x+h[v]+4,l,r,-1);}break;
		case'|':{ll ls=0;rev(i,u,v)dfs(x+h[u],y+3,v),h[u]+=h[v]+1,qmax(w[u],w[v]+6),ls=h[v];h[u]--;ll l=y,r=y+w[u]-1;
		rep(i,x+2,x+h[u]-ls)ans[i][l]=ans[i][r]='|';ll now=x+1;rev(i,u,v)line(now,l,r,w[v]),now+=h[v]+1;}break;
		case 0 :{ll l=0;rev(i,u,v)l?memcpy(ans[x+1]+y+w[u]-2,"->",2),0:l=1,
		dfs(x,y+w[u],v),qmax(h[u],h[v]),w[u]+=w[v]+2;w[u]-=2;}break;
		default:{ll n=strlen(s[-z[u]]),r=y+(w[u]=n+4)-1;h[u]=3;line(x,y,r,-2),line(x+2,y,r,-2);
		rep(i,x,x+2)ans[i][y]=ans[i][r]='+';memcpy(ans[x+1]+y+2,s[-z[u]],n);}
	}
}
int main(){aN w;
	scanf("%s",t+1);ll n=strlen(t+1);w['|']=0,w[0]=1,w['+']=w['*']=w['?']=2;rep(i,'A','Z')w[i]=3;w['(']=w[')']=-1;
	memset(ans,' ',sizeof ans);t[0]='(',t[n+1]=')';c[0]=-1;rep(i,0,n+1)switch(w[t[i]]){
		case-1:if(t[i]==')'){if(!c[tc]){for(++tz;!c[tc];tc--)add(tz,num[tn--]);add(tz,num[tn]);z[num[tn]=tz]=0;}
		if(c[tc]=='|'){for(++tz;c[tc]=='|';tc--)add(tz,num[tn--]);add(tz,num[tn]);z[num[tn]=tz]='|';}
		tc--;if(w[t[i+1]]==3||t[i+1]=='(')c[++tc]=0;}else c[++tc]=t[i];break;
		case 0:if(!c[tc]){for(++tz;!c[tc];tc--)add(tz,num[tn--]);add(tz,num[tn]);z[num[tn]=tz]=0;}c[++tc]='|';break;
		case 2:add(++tz,num[tn]);;z[num[tn]=tz]=t[i];if(w[t[i+1]]==3||t[i+1]=='(')c[++tc]=0;break;
		case 3:if(w[t[i+1]]==2)s[++ts][0]=t[i],z[num[++tn]=++tz]=-ts;else{z[num[++tn]=++tz]=-++ts;s[ts][0]=t[i];
		for(ll tt=0;w[t[i+1]]==3&&w[t[i+2]]!=2;s[ts][++tt]=t[++i]);if(w[t[i+1]]==3||t[i+1]=='(')c[++tc]=0;}
	}ll r=num[1];dfs(0,3,r);ll a=h[r],b=::w[r]+6;memcpy(ans[1],"S->",3),memcpy(ans[1]+b-3,"->F",3);
	printf("%lld %lld\n",a,b);ref(i,0,h[r]){ll t=b;char*s=ans[i];if(s[t]==' ')s[t--]=0;puts(s);}return 0;
}/*{printf("add %c:\n",t[i]);rep(i,1,tc)printf("%c",c[i]?:'_');puts("");rep(i,1,tn)printf("%lld ",num[i]);puts("");}*/
/*printf("%lld->%lld\n",u,v);*/
//NE?(ER)C++|(IS)*?|(CHA((LL))ENGING)//A(B) (A|B)+|C
#if 0
XXX
+-----+
+.XXX.+
+-----+
+
...####...
+->####->+
|..####..|
|..####..|
|........|
+<-------+
?
..........
+------->+
|........|
|..####..|
+->####->+
...####...
...####...
*
..........
+------->+
|........|
|..####..|
+->####->+
|..####..|
|..####..|
|........|
+<-------+

####..#####
####->#####
####..#####
####.......
####.......

...######...
+->######->+
|..######..|
|..........|
|..##......|
+->##----->+
|..##......|
|..##......|
|..##......|
|..##......|
|..........|
|..####....|
+->####--->+
...####.....
...####.....

c?*
.................
+-------------->+
|...............|
|...............|
+->+-------->+->+
|..|.........|..|
|..|..+---+..|..|
|..+->+.c.+->+..|
|.....+---+.....|
|...............|
+<--------------+

#endif