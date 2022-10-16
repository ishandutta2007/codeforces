#include <cstdio>
#include <set>
#include <vector>
#include <cstdlib>

const int INF=1e9+7;

struct Castle{
  int coords[4];
  void read(){
    for(int i=0;i<4;i++){
      scanf("%d",&coords[i]);
    }
    //negate for symmetry
    coords[2]*=-1;
    coords[3]*=-1;
  }
}castles[100005];

template<int D>
struct CastleCmp{
  bool operator()(Castle a,Castle b){
    for(int i=0;i<4;i++){
      int j=i^D;
      if(a.coords[j]!=b.coords[j]){
	return a.coords[j]<b.coords[j];
      }
    }
    return false;
  }
};


struct SuperSet{
  std::set<Castle,CastleCmp<0> > ord0;
  std::set<Castle,CastleCmp<1> > ord1;
  std::set<Castle,CastleCmp<2> > ord2;
  std::set<Castle,CastleCmp<3> > ord3;
  SuperSet(){
  }
  template<class Iterator>
  SuperSet(Iterator begin,Iterator end):ord0(begin,end),ord1(begin,end),ord2(begin,end),ord3(begin,end){
  }
};

void shatter(SuperSet& set);

template<int D>
bool split(std::set<Castle,CastleCmp<D> >& ord,int limit,SuperSet& set){
  int max=-INF;
  for(auto it=ord.begin();it!=ord.end()&&limit-->0;it++){
    if(max!=-INF&&it->coords[D]>=max){
      std::vector<Castle> sub(ord.begin(),it);
      SuperSet set2;
      for(auto c:sub){
	set.ord0.erase(c);
	set.ord1.erase(c);
	set.ord2.erase(c);
	set.ord3.erase(c);
	set2.ord0.insert(c);
	set2.ord1.insert(c);
	set2.ord2.insert(c);
	set2.ord3.insert(c);
      }
      shatter(set);
      shatter(set2);
      return true;
    }
    max=std::max(max,-it->coords[D^2]);
  }
  return false;
}

void shatter(SuperSet& set){
  if(set.ord0.size()==1) return;
  for(int limit=1;limit<set.ord0.size()*2;limit*=2){
    if(split(set.ord0,limit,set)) return;
    if(split(set.ord1,limit,set)) return;
    if(split(set.ord2,limit,set)) return;
    if(split(set.ord3,limit,set)) return;
  }
  printf("NO\n");
  exit(0);
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    castles[i].read();
  }
  SuperSet set(castles,castles+N);
  shatter(set);
  printf("YES\n");
}