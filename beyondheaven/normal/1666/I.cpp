#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=1e5+10;
int R,C;

struct point{
  int x,y;
  bool operator==(point o){
    return x==o.x&&y==o.y;
  }
}A,B;
int qdis(const point A,const point B){
  return abs(A.x-B.x)+abs(A.y-B.y);
}

int tid(int x,int y){
  return (x-1)*C+y;
}
point dit(int id){
  int x=(id-1)/C+1;
  int y=(id-1)%C+1;
  return{x,y};
}

int res;
int dig(int r,int c){
  printf("DIG %d %d\n",r,c),fflush(stdout);int x;cin>>x;return x;
  res++;
  return A==point{r,c}||B==point{r,c};
}
int scan(int r,int c){
  printf("SCAN %d %d\n",r,c),fflush(stdout);int x;cin>>x;return x;
  res++;
  return qdis(A,{r,c})+qdis(B,{r,c});
}

int dig(int r,int c,point A,point B){
  return A==point{r,c}||B==point{r,c};
}
int scan(int r,int c,point A,point B){
  return qdis(A,{r,c})+qdis(B,{r,c});
}

bool vis[300];
bool can[300][300];
bool hav[20][20];

void solve(){
  res=0;
  mem(hav);
  mem(vis);
  mem(can);
  rep(i,1,R*C)rep(j,i+1,R*C)can[i][j]=1;
  point tpA={0,0},tpB={0,0};
  int tot=0;
  while(1){
    point pos={0,0};int mn=1e9,ct=0;
    rep(i,1,R*C)rep(j,i+1,R*C)if(can[i][j])ct++,tpA=dit(i),tpB=dit(j);
    if(ct==1)break;
    pii dat[100000];
    int len=0;
    if(++tot==1){
      mn=0;
      pos={1,1};
      goto jum;
    }
    rep(a,1,R*C)rep(b,a+1,R*C)if(can[a][b]){
      dat[++len]={a,b};
    }
    rep(x,1,R)rep(y,1,C)if(!hav[x][y]){
      static int buk[72];
      mem(buk);
      int mp=0;
      rep(_,1,len){
        int a=dat[_].first;
        int b=dat[_].second;
        int tp=scan(x,y,dit(a),dit(b));
        buk[tp]++;
        chkmax(mp,tp);
      }
      bool only=1;
      rep(i,1,mp)if(buk[i]){
        rep(j,i+1,mp)if(buk[j]){
          only=0;break;
        }
        break;
      }
      if(!only){
        int v=0;
        rep(i,1,mp)chkmax(v,buk[i]);
        if(mn>v){
          mn=v;
          pos={x,y};
        }
      }
    }
    jum:
      ;
    if(mn>1e8){
      rep(i,1,R*C)rep(j,i+1,R*C)if(can[i][j]){
        int chk=i;
        if(vis[i])chk=j;
        point p=dit(chk);
        vis[chk]=1;
        int tp=dig(p.x,p.y);
        if(tp==0){
          can[i][j]=0;
        }else{
          rep(a,1,R*C)rep(b,a+1,R*C){
            if(a!=chk&&b!=chk)can[a][b]=0;
          }
        }
        goto GG;
      }
      GG:
        ;
    }else{
      hav[pos.x][pos.y]=1;
      int v=scan(pos.x,pos.y);
      rep(i,1,R*C)rep(j,i+1,R*C)if(can[i][j]){
        int ano=scan(pos.x,pos.y,dit(i),dit(j));
        if(ano!=v){
          can[i][j]=0;
        }
      }
    }
  }
  if(!vis[tid(tpA.x,tpA.y)])dig(tpA.x,tpA.y);
  if(!vis[tid(tpB.x,tpB.y)])dig(tpB.x,tpB.y);
//  printf("(%d %d), (%d %d) : #%d, (%d %d), (%d %d)\n",A.x,A.y,B.x,B.y,res,tpA.x,tpA.y,tpB.x,tpB.y);
//  assert(A==tpA&&B==tpB);
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  int t;cin>>t;
  while(t--){
    cin>>R>>C;
    solve();
  }
//  R=2,C=3;
//  A={1,2},B={1,3};
//  R=16,C=16;
//  while(1){
//    int i,j;
//    do{
//      i=Rnd()%(R*C)+1;
//      j=Rnd()%(R*C)+1;
//      if(i>j)swap(i,j);
//    }while(i==j);
//    A=dit(i);
//    B=dit(j);
//    solve();
//  }
//  rep(i,1,R*C)rep(j,i+1,R*C){
//    A=dit(i);
//    B=dit(j);
//    swap(A,B);
//    solve();
//  }
//  solve();
  orzjk::flush();
  return 0;
}