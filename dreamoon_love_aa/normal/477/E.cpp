#include <bits/stdc++.h>
#define PB push_back
typedef long long LL;
using namespace std;
const int SIZE = 4e5+1;
const int MAX = 1e9;
int n,a[SIZE],an[SIZE],d[SIZE<<2],stk[SIZE],ml[SIZE];
struct data{
    int x1,y1,y2,id;
    data(int _x1,int _y1,int _y2,int _id){x1=_x1;y1=_y1;y2=_y2;id=_id;}
};
vector<data>in[2][SIZE],emp;
vector<pair<int,int> >rmq_query[SIZE];
void fresh(int& x,int v){if(x>v)x=v;}
void init(int r[],int id,int L,int R){
    r[id]=MAX;
    if(L==R)return;
    int M=(L+R)>>1;
    init(r,id<<1,L,M);
    init(r,(id<<1)|1,M+1,R);
}
int qq(int r[],int id,int L,int R,int ll,int rr){
    if(ll<=L&&R<=rr)return r[id];
    int M=(L+R)>>1;
    if(rr<=M)return qq(r,id<<1,L,M,ll,rr);
    if(M<ll)return qq(r,(id<<1)|1,M+1,R,ll,rr);
    return min(qq(r,id<<1,L,M,ll,rr),qq(r,(id<<1)|1,M+1,R,ll,rr));
}
void insert(int r[],int id,int L,int R,int x,int v){
    fresh(r[id],v);
    if(L==R)return;
    int M=(L+R)>>1;
    if(x<=M)insert(r,id<<1,L,M,x,v);
    else insert(r,(id<<1)|1,M+1,R,x,v);
}
void erase(int r[],int id,int L,int R,int x){
    if(L==R){
        r[id]=MAX;
        return;
    }
    int M=(L+R)>>1;
    if(x<=M)erase(r,id<<1,L,M,x);
    else erase(r,(id<<1)|1,M+1,R,x);
    r[id]=min(r[id<<1],r[(id<<1)|1]);
}
void Go(vector<data>input[]){
    int i,j,k;
    init(d,1,0,n-1);
    for(i=1,k=0;i<=n;i++){
        while(k>0&&a[i]<=a[stk[k-1]]){
            erase(d,1,0,n-1,k-1);
            k--;
        }
        stk[k++]=i;
        insert(d,1,0,n-1,k-1,a[i]-2*i);
        for(j=0;j<(int)input[i].size();j++){
            int ll=0,rr=k,ll2=-1,rr2=k-1;
            while(ll<rr){
                int mm=(ll+rr)>>1;
                if(a[stk[mm]]<=input[i][j].y2)ll=mm+1;
                else rr=mm;
            }
            while(ll2<rr2){
                int mm2=(ll2+rr2+1)>>1;
                if(stk[mm2]>input[i][j].x1)rr2=mm2-1;
                else ll2=mm2;
            }
            // case: no end
            if(input[i][j].x1<=i){
                if(min(ml[input[i][j].id],input[i][j].y1)<=input[i][j].y2)fresh(an[input[i][j].id],abs(input[i][j].x1-i)+input[i][j].y2-min(ml[input[i][j].id],input[i][j].y1));
                else{
                    fresh(an[input[i][j].id],abs(input[i][j].x1-i)+min(ml[input[i][j].id],input[i][j].y1)-input[i][j].y2);
                    if(ll>0)fresh(an[input[i][j].id],input[i][j].x1+i-2*stk[ll-1]+input[i][j].y2-a[stk[ll-1]]);
                    if(ll<=ll2)fresh(an[input[i][j].id],qq(d,1,0,n-1,ll,ll2)+i+input[i][j].x1-input[i][j].y2);
                }
            }
            if(input[i][j].x1>=i){
                if(min(ml[input[i][j].id],input[i][j].y1)>input[i][j].y2){
                    if(ll>0)fresh(an[input[i][j].id],input[i][j].x1+i-2*stk[ll-1]+input[i][j].y2-a[stk[ll-1]]);
                    if(ll<=ll2)fresh(an[input[i][j].id],qq(d,1,0,n-1,ll,ll2)+i+input[i][j].x1-input[i][j].y2);
                }
            }
            // case: contain end
            if(input[i][j].x1<=i){
                if(ll!=k){
                    if(stk[ll]>=input[i][j].x1)fresh(an[input[i][j].id],i-input[i][j].x1+1+a[stk[ll]]-input[i][j].y2);
                    else{
                        fresh(an[input[i][j].id],qq(d,1,0,n-1,ll,ll2)+i+input[i][j].x1-input[i][j].y2+1);
                        if(ll2+1<k)fresh(an[input[i][j].id],i-input[i][j].x1+a[stk[ll2+1]]-input[i][j].y2+1);
                    }
                }
                if(ll){
                    if(stk[ll-1]>=input[i][j].x1)fresh(an[input[i][j].id],i-input[i][j].x1+1+input[i][j].y2-a[stk[ll-1]]);
                    else fresh(an[input[i][j].id],i+input[i][j].x1-2*stk[ll-1]+input[i][j].y2-a[stk[ll-1]]+1);
                }
            }
            if(input[i][j].x1>=i){
                if(ll)fresh(an[input[i][j].id],i+input[i][j].x1-2*stk[ll-1]+input[i][j].y2-a[stk[ll-1]]+1);
                if(ll!=k&&ll2>=ll)fresh(an[input[i][j].id],qq(d,1,0,n-1,ll,ll2)+i+input[i][j].x1-input[i][j].y2+1);
            }
        }
    }
}
int BIT[SIZE];
void BIT_ins(int x,int v){for(;x<SIZE;x+=x&-x)fresh(BIT[x],v);}
int BIT_qq(int x){int res=MAX;for(;x;x-=x&-x)res=min(res,BIT[x]);return res;}
int main(){
    int Q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        in[0][x2].PB(data(x1,y1,y2,i));
        in[1][n+1-x2].PB(data(n+1-x1,y1,y2,i));
        rmq_query[max(x1,x2)].PB(make_pair(min(x1,x2),i));
        an[i]=abs(x1-x2)+y2+1;    // case: contain home
    }
    memset(BIT,0x7f,sizeof(BIT));
    for(int i=1;i<=n;i++){
        BIT_ins(n+1-i,a[i]);
        for(int j=0;j<rmq_query[i].size();j++)
            ml[rmq_query[i][j].second]=BIT_qq(n+1-rmq_query[i][j].first);
    }
    Go(in[0]);
    reverse(a+1,a+n+1);
    Go(in[1]);
    for(int i=0;i<Q;i++)printf("%d\n",an[i]);
    return 0;
}