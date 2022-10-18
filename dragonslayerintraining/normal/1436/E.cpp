#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int as[100005];
int st[200005];
int mex[100005];
int N;

void update(int i,int v){
  for(st[i+=N]=v;i>0;i>>=1){
    st[i>>1]=std::min(st[i],st[i^1]);
  }
}
int query(int a,int b){
  int res=INF;
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) res=std::min(res,st[a++]);
    if(b&1) res=std::min(res,st[--b]);
  }
  return res;
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  int* last=st+N;
  for(int i=1;i<=N;i++){
    if(last[as[i]]<i-1&&query(0,as[i])>last[as[i]]){
      mex[as[i]]=true;
    }
    update(as[i],i);
  }
  for(int v=0;v<=N;v++){
    if(last[v]<N&&query(0,v)>last[v]){
      mex[v]=true;
    }
  }
  int ans=0;
  while(mex[ans]) ans++;
  printf("%d\n",ans+1);
}