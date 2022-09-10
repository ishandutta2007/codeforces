#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 2e6+10;
int INF = 1e9;
int s[2100005];
int tmp1[2100005],tmp2[2100005],cnt[2100005],sa[2100005],*Rank;
void doubling(int m,int n){
	int *x=tmp1,*y=tmp2,num,i,j,len;
	for (i=0;i<m;i++)cnt[i]=0;
	for (i=0;i<n;i++)cnt[s[i]]++;
	for (i=1;i<m;i++)cnt[i]+=cnt[i-1];
	for (i=n-1;i>=0;i--)sa[--cnt[s[i]]]=i;
	for (num=i=1,x[sa[0]]=0;i<n;i++)x[sa[i]]=s[sa[i]]==s[sa[i-1]]?num-1:num++;
	for (len=1;num<n;len<<=1){
		for (j=0;j<len;j++)y[j]=n-len+j;
		for (i=0;i<n;i++)if(sa[i]>=len)y[j++]=sa[i]-len;
		
		for (i=0;i<num;i++)cnt[i]=0;//num
		for (i=0;i<n;i++)cnt[x[i]]++;
		for (i=1;i<num;i++)cnt[i]+=cnt[i-1];
		for (i=n-1;i>=0;i--)sa[--cnt[x[y[i]]]]=y[i];
		
		swap(x,y);
		for (num=i=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+len]==y[sa[i-1]+len]?num-1:num++;
	}
	Rank=x;
}

int a[2000020];
struct SegTree{
    int ma[4194304];
    int n;
    void build(int L,int R,int id){
        if(L==R){
            ma[id]=a[L];
            return;
        }
        int mm=(L+R)>>1;
        build(L,mm,id<<1);
        build(mm+1,R,(id<<1)|1);
        ma[id]=max(ma[id<<1],ma[(id<<1)|1]);
    }
    void init(int _n){
        n=_n;
        build(0,n-1,1);
    }
    int me,v;
    int lll,rr;
    int _qq(int L,int R,int id){
        if(R<lll||rr<L)return 0;
        if(L>=lll&&R<=rr){
            return ma[id];
        }
        int mm=(L+R)>>1;
        int an=-INF;
        if(mm>=lll)an=max(an,_qq(L,mm,id<<1));
        if(mm+1<=rr)an=max(an,_qq(mm+1,R,(id<<1)|1));
        return an;
    }
    int qq(int _lll,int _rr){
        lll=_lll;
        rr=_rr;
        return _qq(0,n-1,1);
    }
}seg;
char input[SIZE];
int main(){
    RS(input);
    int n=LEN(input);
    int alll=0;
    REP(i,n){
        input[i+n]=input[i];
        s[i+n]=s[i]=input[i]=='('?0:1;
        if(input[i]=='(')alll++;
        else alll--;
    }
    doubling(2,2*n+1);
    if(input[0]==')')a[0]=1;
    else a[0]=-1;
    REPP(i,1,2*n){
        if(input[i]==')')a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
    }
    int mi=INF,st=-1,now=0,an_lll,an_rr;
    seg.init(2*n);
    REP(i,n){
        int lll=seg.qq(i,i+n-1)+now;
        lll=max(lll,-alll);
        lll=max(lll,0);
        int rr=lll+alll;
        if(lll+rr+n<mi||(lll+rr+n==mi&&(st==-1||Rank[i]<Rank[st]))){
            st=i;
            mi=n+lll+rr;
            an_lll=lll;
            an_rr=rr;
        }
        if(input[i]==')')now--;
        else now++;
    }
    REP(i,an_lll)printf("(");
    input[st+n]=0;
    printf("%s",input+st);
    REP(i,an_rr)printf(")");
    puts("");
    return 0;
}