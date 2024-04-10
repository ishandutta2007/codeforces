#include <cstdio>

const int MOD=998244353;

struct State{
  int ways[2][2];
  int l,r;
  State(){
    ways[0][0]=ways[0][1]=ways[1][0]=ways[1][1]=0;
  }
}st[1000006];
int N;

State combine(State a,State b){
  State res;
  int join=(a.r==1)*(9-b.l);
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      res.ways[i][j]=(res.ways[i][j]+1LL*a.ways[i][0]*b.ways[0][j])%MOD;
      res.ways[i][j]=(res.ways[i][j]+1LL*a.ways[i][1]*b.ways[1][j]%MOD*join)%MOD;
    }
  }
  res.l=a.l;
  res.r=b.r;
  return res;
}

State leaf(int d){
  State res;
  res.l=res.r=d;
  res.ways[0][0]=d+1;
  res.ways[0][1]=res.ways[1][0]=1;
  return res;
}

State ident(){
  State res;
  res.l=res.r=0;
  res.ways[0][0]=1;
  return res;
}

void pull(int w){
  st[w]=combine(st[w<<1],st[w<<1|1]);
}

void update(int i,int d){
  for(st[i+=N]=leaf(d);i>0;i>>=1){
    pull(i>>1);
  }
}

int query(int a,int b){
  State lsum=ident(),rsum=ident();
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) lsum=combine(lsum,st[a++]);
    if(b&1) rsum=combine(st[--b],rsum);
  }
  return combine(lsum,rsum).ways[0][0];
}

char str[1000006];

int main(){
  int M;
  scanf("%d %d",&N,&M);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    update(i,str[i]-'0');
  }
  for(int i=0;i<M;i++){
    int X,D;
    scanf("%d %d",&X,&D);
    update(X-1,D);
    printf("%d\n",query(0,N));
  }
}