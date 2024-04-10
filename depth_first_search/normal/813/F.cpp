#include<bits/stdc++.h>
#define Type template<typename I>
#define N 100000
#define M 200000
#define swap(x,y) (x^=y^=x^=y)
#define INF 1e9
using namespace std;
int n,m,flag,tag[N+M+5];
map<pair<int,int>,int> P; 
struct Operate
{
    int x,y,pos,Begin,End;
}o1[M+5],o2[M+5];
class Class_FIO
{
    private:
        #define Fsize 100000
        #define tc() (A==B&&(B=(A=Fin)+fread(Fin,1,Fsize,stdin),A==B)?EOF:*A++)
        char ch,*A,*B,Fin[Fsize];
    public:
        Class_FIO() {A=B=Fin;}
        Type inline void read(I& x) {x=0;while(!isdigit(ch=tc()));while(x=(x<<3)+(x<<1)+(ch&15),isdigit(ch=tc()));}
        template<typename I,typename... A> inline void read(I& x,A&... y) {read(x),read(y...);}
}F;
class Class_LCT
{
    private:
        #define SIZE (N+M)
        #define PushUp(x)\
        (\
            node[x].Size=node[node[x].Son[0]].Size+node[node[x].Son[1]].Size+(x>n),node[x].Min=x,\
            Val[node[x].Min]>Val[node[node[x].Son[0]].Min]&&(node[x].Min=node[node[x].Son[0]].Min),\
            Val[node[x].Min]>Val[node[node[x].Son[1]].Min]&&(node[x].Min=node[node[x].Son[1]].Min)\
        )
        #define Rever(x) (swap(node[x].Son[0],node[x].Son[1]),node[x].Rev^=1)
        #define PushDown(x) (node[x].Rev&&(Rever(node[x].Son[0]),Rever(node[x].Son[1]),node[x].Rev=0))
        #define Which(x) (node[node[x].Father].Son[1]==x)
        #define Connect(x,y,d) (node[node[x].Father=y].Son[d]=x)
        #define IsRoot(x) (node[node[x].Father].Son[0]^x&&node[node[x].Father].Son[1]^x)
        #define MakeRoot(x) (Access(x),Splay(x),Rever(x))
        #define Split(x,y) (MakeRoot(x),Access(y),Splay(y))
        int Stack[SIZE+5];
        struct Tree
        {
            int Min,Size,Rev,Father,Son[2];
        }node[SIZE+5];
        inline void Rotate(int x)
        {
            register int fa=node[x].Father,pa=node[fa].Father,d=Which(x);
            !IsRoot(fa)&&(node[pa].Son[Which(fa)]=x),node[x].Father=pa,Connect(node[x].Son[d^1],fa,d),Connect(fa,x,d^1),PushUp(fa),PushUp(x);
        }
        inline void Splay(int x)
        {
            register int fa=x,Top=0;
            while(Stack[++Top]=fa,!IsRoot(fa)) fa=node[fa].Father;
            while(Top) PushDown(Stack[Top]),--Top;
            while(!IsRoot(x)) fa=node[x].Father,!IsRoot(fa)&&(Rotate(Which(x)^Which(fa)?x:fa),0),Rotate(x);
        }
        inline void Access(int x) {for(register int son=0;x;x=node[son=x].Father) Splay(x),node[x].Son[1]=son,PushUp(x);}
    public:
        int Val[SIZE+5];
        Class_LCT() {Val[0]=INF;}
        inline void Init(int len) {for(register int i=1;i<=len;++i) Val[i]=INF,node[i].Min=i;}
        inline void Link(int x,int y) {MakeRoot(x),FindRoot(y)^x&&(node[x].Father=y);}
        inline void Cut(int x,int y) {MakeRoot(x),!(FindRoot(y)^x)&&!(node[y].Father^x)&&!node[y].Son[0]&&(node[y].Father=node[x].Son[1]=0,PushUp(x));}
        inline int FindRoot(int x) 
        {
            Access(x),Splay(x);
            while(node[x].Son[0]) PushDown(x),x=node[x].Son[0];
            return Splay(x),x;
        }
        inline int QueryMin(int x,int y) {return Split(x,y),node[y].Min;}
        inline int QuerySize(int x,int y) {return Split(x,y),node[y].Size;}
        #undef SIZE
}LCT;
inline bool cmp1(Operate x,Operate y) {return x.Begin<y.Begin;}
inline bool cmp2(Operate x,Operate y) {return x.End<y.End;}
inline void Add(int pos)
{
    register int x=o1[pos].x,y=o1[pos].y,z=o1[pos].pos;
    if(!(x^y)) return (void)(tag[z]=1,++flag);
    if(LCT.Val[z]=o1[pos].End,LCT.FindRoot(x)^LCT.FindRoot(y)) return LCT.Link(x,z),LCT.Link(z,y);
    register int p=LCT.QueryMin(x,y);
    if(LCT.Val[z]<LCT.Val[p]) return (void)(!(LCT.QuerySize(x,y)&1)&&(tag[z]=1,++flag));
    !(LCT.QuerySize(x,y)&1)&&(tag[p]=1,++flag),LCT.Cut(o1[p-n].x,p),LCT.Cut(p,o1[p-n].y),LCT.Link(x,z),LCT.Link(z,y);
}
inline void Del(int pos)
{
    register int x=o2[pos].x,y=o2[pos].y,z=o2[pos].pos;
    if(tag[z]) return (void)(--flag);
    !(LCT.FindRoot(x)^LCT.FindRoot(z))&&!(LCT.FindRoot(y)^LCT.FindRoot(z))&&(LCT.Cut(x,z),LCT.Cut(z,y),0);
}
int main()
{
    register int Qt,i,p1=1,p2=1,x,y;
    for(F.read(n,Qt),i=1;i<=Qt;++i)
	{
		if(F.read(x,y),P[make_pair(x,y)]) o1[P[make_pair(x,y)]].End=i,P[make_pair(x,y)]=0;
		else P[make_pair(x,y)]=++m,o1[m]=(Operate){x,y,m,i,Qt+1};
	}
	LCT.Init(n+m);
    for(sort(o1+1,o1+m+1,cmp1),i=1;i<=m;++i) o1[i].pos=n+i,o2[i]=o1[i];
    for(sort(o2+1,o2+m+1,cmp2),i=1;i<=Qt;++i)
    {
        while(p1<=m&&o1[p1].Begin<=i) Add(p1++);while(p2<=m&&o2[p2].End<=i) Del(p2++);
        puts(flag?"NO":"YES");
    }
    return 0;
}