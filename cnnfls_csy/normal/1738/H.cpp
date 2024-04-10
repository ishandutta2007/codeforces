#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
/*#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif*/
int n,m,i,j;
struct pam
{
    int ch[1000005][26],go[1000005][26];
    int fa[1000005],len[1000005],cnt;
    int st[2000005],l,r,pl,pr,tl,tr;
    int stkt[1000005],stkl[1000005],stkr[1000005],stkp[1000005],tp;
    void init()
    {
		tl=1;tr=0;
        cnt=1;fa[0]=fa[1]=1;len[1]=-1;len[0]=0;
		int i;fz0k(i,26) ch[0][i]=ch[1][i]=0,go[0][i]=go[1][i]=1;
        l=n+1;r=n;pl=pr=0;tp=0;
        st[l]=st[r]=-1;
    }
    void push_back(int c)
    {
        tp++;stkt[tp]=1;stkl[tp]=pl;stkr[tp]=pr;stkp[tp]=-1;
        st[++r]=c;st[r+1]=-1;
 
        int p=(st[r-len[pr]-1]==c?pr:go[pr][c]),i;
        if(!ch[p][c]){
            stkp[tp]=p;int q=++cnt;
            len[q]=len[p]+2;fz0k(i,26)ch[q][i]=0;
            fa[q]=ch[(st[r-len[fa[p]]-1]==c?fa[p]:go[fa[p]][c])][c];
            ch[p][c]=q;
            fz0k(i,26)go[q][i]=go[fa[q]][i];
            go[q][st[r-len[fa[q]]]]=fa[q];
        }
        pr=ch[p][c];
 
        if(len[pr]==r-l+1) pl=pr;
    }
    void push_front(int c)
    {
        tp++;stkt[tp]=-1;stkl[tp]=pl;stkr[tp]=pr;stkp[tp]=-1;
        st[--l]=c;st[l-1]=-1;
 
        int p=(st[l+len[pl]+1]==c?pl:go[pl][c]),i;
        if(!ch[p][c]){
            stkp[tp]=p;int q=++cnt;
            len[q]=len[p]+2;fz0k(i,26)ch[q][i]=0;
            fa[q]=ch[(st[l+len[fa[p]]+1]==c?fa[p]:go[fa[p]][c])][c];
            ch[p][c]=q;
            fz0k(i,26)go[q][i]=go[fa[q]][i];
            go[q][st[l+len[fa[q]]]]=fa[q];
        }
        pl=ch[p][c];
 
        if(len[pl]==r-l+1) pr=pl;
    }
    void undo()
    {
        int typ=stkt[tp],p=stkp[tp];
        pl=stkl[tp];pr=stkr[tp];tp--;
        int c;if(typ==1) c=st[r],st[r]=-1,r--; else c=st[l],st[l]=-1,l++;
        if(p>-1) ch[p][c]=0,cnt--;
    }
	void print()
	{
		int i;fz(i,l,r) cerr<<((char)('a'+st[i]));cerr<<endl;
	}
}tr;
int cur,fir,mid;
vector<int> v;
int st[1000005];
void push(vector<int> c)
{
	int t=c.size();
	while(t--&&!v.empty()){
		tr.undo();c.push_back(v.back());v.pop_back();
	}
	sort(c.begin(),c.end());
	if(tr.cnt==1){
		ff(c,it) mid=max(mid,*it);
	}
	ff(c,it)if(*it>mid){
		tr.push_back(st[*it]);
		v.push_back(*it);
	}
	reverse(c.begin(),c.end());
	ff(c,it)if(*it<=mid){
		tr.push_front(st[*it]);
		v.push_back(*it);
	}
}
void pop(int x)
{
	vector<int> c;
	while(v.back()!=x){
		c.push_back(v.back());
		v.pop_back();tr.undo();
	}
	v.pop_back();tr.undo();
	assert(v.empty()||x<=mid);
	push(c);
}
int main()
{
	read(n);
	tr.init();
	fz1(i,n){
		char op;while(!islower(op=getchar()));op=getchar();
		if(op=='u'){
			getchar();getchar();
			char c;while(!islower(c=getchar()));
			cur++;st[cur]=c-'a';
			v.push_back(cur);tr.push_back(st[cur]);
		}
		else{
			getchar();pop(++fir);
		}
		printf("%d\n",tr.cnt-1);
//		tr.print();
	}
	return 0;
}