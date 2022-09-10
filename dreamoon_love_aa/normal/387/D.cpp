#include<stdio.h>
#include<vector>
#include<string.h>
#define FN 5010 
#define FM 500010 
#define INF 1023456789 
using namespace std;
struct E {
    int k,c;
    E(){}
    E( int _k, int _c ):k(_k),c(_c){}
} es[FM*2];

struct Flow {

    int n,m,dis[FN],ptr[FN];
    int qq[FN],qr,ql;
    vector<int> e[FN];
    void init( int _n ) {
        n=_n; m=0;
        for ( int i=0; i<n; i++ ) e[i]=vector<int>();
    }
    void add( int a, int b, int c ) {
        e[a].push_back(m); es[m]=E(b,c); m++;
        e[b].push_back(m); es[m]=E(a,0); m++;
    }
    bool BFS() {
        memset(dis,-1,n*sizeof(int));
        ql=qr=0;
        qq[qr++]=0;
        dis[0]=0;
        while ( ql!=qr && dis[n-1]==-1 ) {
            int p=qq[ql++];
            for(int i=0;i < (int)e[p].size(); i++) {
                E ee=es[ e[p][i] ];
                if ( ee.c==0 || dis[ee.k]!=-1 ) continue;
                dis[ee.k]=dis[p]+1;
                qq[qr++]=ee.k;
            }
        }
        return dis[n-1]!=-1;
    }
    int go( int p, int c ) {
        if ( p==n-1 ) return c;
        int tmp;

        for(int i=ptr[p]; i<(int)e[p].size(); i++) {
            E &ee=es[e[p][i]];
            if ( ee.c==0 || dis[p]+1!=dis[ee.k] ) continue;
            tmp=go(ee.k,min(c,ee.c));

            if(tmp != 0){
                ee.c-=tmp; es[e[p][i]^1].c+=tmp;
                ptr[p]=i;
                return tmp;
            }
        }
        ptr[p] = (int)e[p].size();
        return 0;
    }
    int maxflow() {
        long long ret=0; 
        while ( BFS() ){
            for(int i=0;i<n;i++)ptr[i]=0;
            while(true){
                int tmp=go(0,INF);
                if(tmp)ret+=tmp;
                else break;
            }
        }
        return ret;
    }
} flow;
int my_edge[1000][2];
int fetch(int x,int O,int hd){
    if(x>=O)x--;
    return x*2-hd;
}
int main(){
    int n,m,an=INF;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&my_edge[i][0],&my_edge[i][1]);
    }
    for(int i=1;i<=n;i++){
        flow.init(n*2);
        int need=0;
        for(int j=1;j<n;j++){
            flow.add(0,j*2-1,1);
            flow.add(j*2,n*2-1,1);
        }
        for(int j=0;j<m;j++){
            if(my_edge[j][0]==i||my_edge[j][1]==i)need++;
            else{
                flow.add(fetch(my_edge[j][0],i,1),fetch(my_edge[j][1],i,0),1);
            }
        }
        int res=flow.maxflow();
        an=min(an,n*2-1-need+((m-need)-res)+(n-1-res));
    }
    printf("%d\n",an);
    return 0;
}