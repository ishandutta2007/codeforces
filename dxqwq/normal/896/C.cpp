// Problem: CF896C Willem, Chtholly and Seniorious
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF896C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int qp(int x,int y,int p)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
struct Node{
    int l, r;
    mutable int val;
    Node(int a=-1,int b=-1,int c=0){l=a,r=b,val=c;}
    bool operator<(const Node&a)const{return l<a.l;}
};
set<Node> st;
set<Node>::iterator split(int pos)
{
    auto it=st.lower_bound(Node(pos));
    if (it!=st.end()&&it->l==pos) return it;
    --it;Node tmp=*it;st.erase(it);
    st.insert(Node(tmp.l,pos-1,tmp.val));
    return st.insert(Node(pos,tmp.r,tmp.val)).first; 
}
void assign(int l,int r,int val)
{
	auto itr=split(r+1),itl=split(l);
    st.erase(itl,itr),st.insert((Node){l, r, val});
}
void add(int l,int r,int val)
{
    auto itr=split(r+1),itl=split(l);
    for(auto it=itl; it!=itr; ++it)
        it->val=it->val+val;
}
int query(int l,int r,int T,int P)
{
    auto itr=split(r+1),itl=split(l);
    int res=0;
    for(auto it=itl; it!=itr; ++it)
        (res+=(it->r-it->l+1)*qp((it->val)%P,T,P)%P)%=P;
    return res;
}
int kth(int l,int r,int g)
{
	auto itr=split(r+1),itl=split(l);
	vector<pair<int,int> > v;
	for(auto it=itl; it!=itr; ++it)
		v.push_back(make_pair(it->val,(it->r)-(it->l)+1));
	sort(v.begin(),v.end());
	for(auto i:v) if(g<=i.second) return i.first;
	else g-=i.second;
	return 998244353;
}
int n,m,seed,mx;
int rnd()
{
	int res=seed;
	seed=(seed*7+13)%1000000007;
	return res;
}
int getv(){return rnd()%mx+1;}
void GET(int&A,int&B,int&C,int&D,int&E)
{
	A=rnd()%4+1,B=rnd()%n+1,C=rnd()%n+1;
	if(B>C) swap(B,C);
	if(A==3) D=rnd()%(C-B+1)+1;
	else D=getv();
	if(A==4) E=getv();
}
signed main()
{
	n=read(),m=read(),seed=read(),mx=read();
	st.insert((Node){(int)0xc0c0c0c0c0c0c0c0,0,0});
	for(int i=1; i<=n; ++i) st.insert((Node){i,i,getv()});
	st.insert((Node){n+1,(int)0x3f3f3f3f3f3f3f3f,0});
	for(int op,l,r,x,y,I=1; I<=m; ++I)
	{
		GET(op,l,r,x,y);
		if(op==1)
			add(l,r,x);
		else if(op==2)
			assign(l,r,x);
		else if(op==3)
			printf("%lld\n",kth(l,r,x));
		else 
			printf("%lld\n",query(l,r,x,y)%y);
	}
	return 0;
}