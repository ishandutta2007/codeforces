#include <cstdio>
#include <vector>
#include <random>
#include <chrono>
#include <cassert>
#include <algorithm>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int MAXN=100005;
const int BLOCK=600;

int BASE;
int IBASE;
const int MOD=1e9+7;
int hpow[MAXN]={1};
int ihpow[MAXN]={1};

int modexp(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

struct HashedString;
struct HashedSubstring;
struct HashedSubstring{
  HashedString* base;
  int l,r;
  int length(){return r-l;}
};

struct HashedString{
  std::vector<int> data;
  std::vector<int> prefix;
  HashedString(std::vector<int> data={}):data(data),prefix(data.size()+1){
    for(int i=0;i<data.size();i++){
      prefix[i+1]=(prefix[i]+1LL*hpow[i]*data[i])%MOD;
    }
  }
  int query(int l,int r){
    return 1LL*(prefix[r]-prefix[l]+MOD)*ihpow[l]%MOD;
  }
  HashedSubstring all(){
    return HashedSubstring{this,0,(int)data.size()};
  }
};

void dump(HashedSubstring& str){
  for(int i=str.l;i<str.r;i++){
    printf(" %d",str.base->query(i,i+1));
  }
}

int ss[MAXN];
int N;
struct Segment{
  HashedString prefix,suffix;
}blocks[MAXN/BLOCK+1];

struct Segment collect(int l,int r){
  std::vector<int> prefix,suffix;
  for(int i=l;i<r;i++){
    if(ss[i]<0){
      if(suffix.empty()){
	prefix.push_back(-ss[i]);
      }else if(suffix.back()==-ss[i]){
	suffix.pop_back();
      }else{
	return Segment{std::vector<int>{0},{}};
      }
    }else{
      suffix.push_back(ss[i]);
    }
  }
  std::reverse(suffix.begin(),suffix.end());
  return Segment{prefix,suffix};
}

void rebuild(int b){
  blocks[b]=collect(b*BLOCK,std::min(N,(b+1)*BLOCK));
}

void cancel(HashedSubstring& a,HashedSubstring& b){
  int low=std::min(a.length(),b.length());
  if(a.base->query(a.l,a.l+low)==b.base->query(b.l,b.l+low)){
  }else{
    return;
  }
  /*
  printf("cancel(");
  dump(a);
  printf(" ,");
  dump(b);
  printf(") => (");
  */
  a.l+=low;
  b.l+=low;
  /*
  dump(a);
  printf(" ,");
  dump(b);
  printf(")\n");
  */
}

bool check(int L,int R){
  std::vector<Segment> store;
  store.reserve(2);
  std::vector<HashedSubstring> prefix,suffix;
  auto add=[&](Segment& seg)->bool{
    HashedSubstring pref=seg.prefix.all(),suff=seg.suffix.all();
    /*printf("ADD:");
    dump(pref);
    printf(" |");
    dump(suff);
    printf("\n");
    */
    while(suffix.size()>0){
      cancel(suffix.back(),pref);
      if(suffix.back().length()==0){
	suffix.pop_back();
      }else if(pref.length()==0){
	break;
      }else{
	return false;
      }
    }
    assert(suffix.empty()||pref.length()==0);
    if(pref.length()){
      prefix.push_back(pref);
    }
    if(suff.length()){
      suffix.push_back(suff);
    }
    return true;
  };
  for(int l=0;l<N;l+=BLOCK){
    int r=std::min(l+BLOCK,N);
    if(l>=L&&r<=R){
      if(!add(blocks[l/BLOCK])) return false;
    }else if(std::max(l,L)<std::min(r,R)){
      store.push_back(collect(std::max(l,L),std::min(r,R)));
      if(!add(store.back())) return false;
    }
  }
  /*
  printf("Result of query:\n");
  printf("Prefix (%d):",(int)prefix.size());
  for(auto sub:prefix){
    for(int i=sub.l;i<sub.r;i++){
      printf(" %d",sub.base->query(i,i+1));
    }
  }
  printf("\n");
  printf("Suffix (%d):",(int)suffix.size());
  for(auto sub:suffix){
    for(int i=sub.l;i<sub.r;i++){
      printf(" %d",sub.base->query(i,i+1));
    }
  }
  printf("\n");
  */
  return prefix.empty()&&suffix.empty();
}

int main(){
  BASE=std::uniform_int_distribution<int>(100000,MOD)(rng);
  IBASE=modexp(BASE,MOD-2);
  for(int i=1;i<MAXN;i++){
    hpow[i]=1LL*hpow[i-1]*BASE%MOD;
    ihpow[i]=1LL*ihpow[i-1]*IBASE%MOD;
  }
  int K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&ss[i]);
  }
  for(int i=0;i<N;i+=BLOCK){
    rebuild(i/BLOCK);
  }
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int T,X,Y;
    scanf("%d %d %d",&T,&X,&Y);
    if(T==1){
      X--;
      ss[X]=Y;
      rebuild(X/BLOCK);
    }else{
      X--;
      if(check(X,Y)){
	printf("Yes\n");
      }else{
	printf("No\n");
      }
    }
  }
}