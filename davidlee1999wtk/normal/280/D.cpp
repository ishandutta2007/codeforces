#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char _ch;
int _op;

inline void getint(int &_x)
{
	_x=0;
	for(_ch=getchar();_ch>'9'||_ch<'0';_ch=getchar());
	for(;_ch<='9'&&_ch>='0';_ch=getchar())
		_x=_x*10+_ch-48;
}

inline void getint2(int &_x)
{
	_x=0;
	_op=1;
	for(_ch=getchar();_ch>'9'||_ch<'0';_ch=getchar())
        if(_ch=='-')
            _op=-1;
	for(;_ch<='9'&&_ch>='0';_ch=getchar())
		_x=_x*10+_ch-48;
    _x*=_op;
}

int ml[N*4],nl[N*4],mr[N*4],nr[N*4],lm[N*4],ln[N*4],rm[N*4],rn[N*4],sm[N*4],sn[N*4],flag[N*4],sum[N*4];
int a[N],ql,qr,qk,qw,fl[25],fr[25],lsn[N*4],lsm[N*4],rsn[N*4],rsm[N*4],ans,nml,nlm,la,ra;
inline void push_up(int o)
{
    int lc=o<<1,rc=o<<1|1;
    //debug(sum[lc]);
    //debug(
    if(ml[lc]<=sum[lc]+ml[rc])
    {
        ml[o]=sum[lc]+ml[rc];
        lm[o]=lm[rc];
    }
    else
    {
        ml[o]=ml[lc];
        lm[o]=lm[lc];
    }
    if(nl[lc]>=sum[lc]+nl[rc])
    {
        nl[o]=sum[lc]+nl[rc];
        ln[o]=ln[rc];
    }
    else
    {
        nl[o]=nl[lc];
        ln[o]=ln[lc];
    }

    if(mr[rc]<=sum[rc]+mr[lc])
    {
        mr[o]=sum[rc]+mr[lc];
        rm[o]=rm[lc];
    }
    else
    {
        mr[o]=mr[rc];
        rm[o]=rm[rc];
    }
    if(nr[rc]>=sum[rc]+nr[lc])
    {
        nr[o]=sum[rc]+nr[lc];
        rn[o]=rn[lc];
    }
    else
    {
        nr[o]=nr[rc];
        rn[o]=rn[rc];
    }
    //debug(sm[lc]);
    //debug(sm[rc]);
    if(mr[lc]+ml[rc]>=sm[lc]&&mr[lc]+ml[rc]>=sm[rc])
    {
        sm[o]=mr[lc]+ml[rc];
        lsm[o]=rm[lc];
        rsm[o]=lm[rc];
    }
    else if(sm[lc]>=sm[rc])
    {
        sm[o]=sm[lc];
        lsm[o]=lsm[lc];
        rsm[o]=rsm[lc];
    }
    else
    {
        sm[o]=sm[rc];
        //debug(sm[rc]);
        lsm[o]=lsm[rc];
        rsm[o]=rsm[rc];
    }

    if(nr[lc]+nl[rc]<=sn[lc]&&nr[lc]+nl[rc]<=sn[rc])
    {
        sn[o]=nr[lc]+nl[rc];
        lsn[o]=rn[lc];
        rsn[o]=ln[rc];
    }
    else if(sn[lc]<=sn[rc])
    {
        sn[o]=sn[lc];
        lsn[o]=lsn[lc];
        rsn[o]=rsn[lc];
    }
    else
    {
        sn[o]=sn[rc];
        lsn[o]=lsn[rc];
        rsn[o]=rsn[rc];
    }
    sum[o]=sum[lc]+sum[rc];
}

inline void put_flag(int o)
{
    flag[o]^=1;
    swap(sm[o],sn[o]);
    sm[o]*=-1;
    sn[o]*=-1;
    swap(nl[o],ml[o]);
    swap(nr[o],mr[o]);
    nl[o]*=-1;
    ml[o]*=-1;
    nr[o]*=-1;
    mr[o]*=-1;
    swap(ln[o],lm[o]);
    swap(rn[o],rm[o]);
    swap(lsn[o],lsm[o]);
    swap(rsn[o],rsm[o]);
    sum[o]*=-1;
}

inline void push_down(int o)
{
    if(flag[o])
    {
        flag[o]=0;
        put_flag(o<<1);
        put_flag(o<<1|1);
    }
}

void build_tree(int o,int L,int R)
{
    if(L==R)
    {
        ml[o]=a[L];
        mr[o]=a[L];
        nl[o]=a[L];
        nr[o]=a[L];
        lm[o]=L;
        rm[o]=R;
        ln[o]=L;
        rn[o]=R;
        sm[o]=a[L];
        sn[o]=a[L];
        sum[o]=a[L];
        lsm[o]=L;
        rsm[o]=R;
        lsn[o]=L;
        rsn[o]=R;
        return;
    }
    int mid=(L+R)>>1;
    build_tree(o<<1,L,mid);
    build_tree(o<<1|1,mid+1,R);
    push_up(o);
    //debug(o);
    //debug(L);
    //debug(R);
    //debug(lsn[o]);
    //debug(rsn[o]);
    //debug(sm[o]);
    //debug(mr[o]);
    //debug(ml[o]);
    //debug(sn[o]);
}

void Change(int o,int L,int R)
{
    if(L==R)
    {
        ml[o]=a[L];
        mr[o]=a[L];
        nl[o]=a[L];
        nr[o]=a[L];
        //lm[o]=L;
        //rm[o]=R;
        //ln[o]=L;
        //rn[o]=R;
        sm[o]=a[L];
        sn[o]=a[L];
        sum[o]=a[L];
        //lsm[o]=L;
        //rsm[o]=R;
        //lsn[o]=L;
        //rsn[o]=R;
        return;
    }
    push_down(o);
    int mid=(L+R)>>1;
    if(qk<=mid)
        Change(o<<1,L,mid);
    else Change(o<<1|1,mid+1,R);
    push_up(o);
}

void Change2(int o,int L,int R)
{
    if(L>=ql&&R<=qr)
    {
        put_flag(o);
        return;
    }
    push_down(o);
    int mid=(L+R)>>1;
    if(ql<=mid)
        Change2(o<<1,L,mid);
    if(qr>mid)
        Change2(o<<1|1,mid+1,R);
    push_up(o);
}

void Query(int o,int L,int R)
{
    if(L>=ql&&R<=qr)
    {
        //debug(sm[o]);
        if(sm[o]>ans&&sm[o]>=nml+ml[o])
        {
            ans=sm[o];
            //debug(lsm[o]);
            //debug(rsm[o]);
            //debug(lsn[o]);
            //debug(rsn[o]);
            la=lsm[o];
            ra=rsm[o];
        }
        else if(nml+ml[o]>ans)
        {
            ans=nml+ml[o];
            la=nlm;
            ra=lm[o];
        }
        if(mr[o]>=nml+sum[o])
        {
            nml=mr[o];
            nlm=rm[o];
        }
        else
        {
            nml=nml+sum[o];
            //nlm=nlm;
        }
        return;
    }
    push_down(o);
    int mid=(L+R)>>1;
    if(ql<=mid)
        Query(o<<1,L,mid);
    if(qr>mid)
        Query(o<<1|1,mid+1,R);
}

int main()
{
    int n,m,i,op,sum,l,r;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        getint2(a[i]);
        //scanf("%d",&a[i]);
    }
    build_tree(1,1,n);
    cin>>m;
    while(m--)
    {
        getint(op);
        //scanf("%d",&op);
        if(op==0)
        {
            getint(qk);
            getint2(qw);
            //scanf("%d%d",&qk,&qw);
            a[qk]=qw;
            Change(1,1,n);
        }
        else
        {
            getint(l);
            getint(r);
            getint(qk);
            //scanf("%d%d%d",&l,&r,&qk);
            sum=0;
            for(i=1;i<=qk;i++)
            {
                ans=-INF,nml=-INF;
                nlm=0;
                ql=l,qr=r;
                Query(1,1,n);
                if(ans<=0)
                    break;
                else
                {
                    sum+=ans;
                    fl[i]=la;
                    fr[i]=ra;
                    //debug(ans);
                    //debug(la);
                    //debug(ra);
                    ql=la,qr=ra;
                    Change2(1,1,n);
                }
            }
            printf("%d\n",sum);
            qk=i-1;
            for(i=1;i<=qk;i++)
            {
                ql=fl[i],qr=fr[i];
                Change2(1,1,n);
            }
        }
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//Cf172 k-Maximum Subsequence Sum
/*
20
-7 -8 -2 -7 10 -2 -3 -1 1 10 9 7 10 -5 -9 3 -8 -2 -4 10
20
1 1 15 3
0 7 -5
0 14 1
1 10 17 2
1 7 19 3
0 11 4
1 8 10 1
0 2 1
0 16 -9
1 4 13 2
1 4 18 2
0 9 -2
1 2 14 2
0 20 4
1 1 15 3
*/