#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>
#include <set>

const int INF=1e9+7;

char str[600005];
int pal[600005];

std::vector<std::array<int,3> > setrcenter;
std::vector<std::array<int,3> > setlcenter;

//closest center to the right of palindromes containing i
int rcenter[600005];
//closest center to the left of palindromes containing i
int lcenter[600005];

struct Node{
  int min,cnt;
  Node():min(INF),cnt(0){
  }
  Node(int min,int cnt):min(min),cnt(cnt){
  }
}st[1<<20];
int lazy[1<<20];

Node combine(Node a,Node b){
  int min=std::min(a.min,b.min);
  return Node(min,(min==a.min)*a.cnt+(min==b.min)*b.cnt);
}

void push(int w,int L,int R){
  if(R-L>1){
    lazy[w<<1]+=lazy[w];
    lazy[w<<1|1]+=lazy[w];
  }
  st[w].min+=lazy[w];
  lazy[w]=0;
}

void pull(int w,int L,int R){
  st[w]=combine(st[w<<1],st[w<<1|1]);
}

void build(int w,int L,int R){
  if(R-L==1){
    st[w]=Node(0,1);
  }else{
    int M=(L+R)/2;
    build(w<<1,L,M);
    build(w<<1|1,M,R);
    pull(w,L,R);
  }
}

void update(int w,int L,int R,int a,int b,int v){
  push(w,L,R);
  if(a>=R||b<=L) return;
  if(a<=L&&b>=R){
    lazy[w]+=v;
    push(w,L,R);
  }else{
    int M=(L+R)/2;
    update(w<<1,L,M,a,b,v);
    update(w<<1|1,M,R,a,b,v);
    pull(w,L,R);
  }
}

Node query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if(a>=R||b<=L) return Node();
  if(a<=L&&b>=R){
    return st[w];
  }else{
    int M=(L+R)/2;
    return combine(query(w<<1,L,M,a,b),query(w<<1|1,M,R,a,b));
  }
}

int main(){
  int N;
  scanf("%d",&N);
  str[0]='^';
  for(int i=0;i<N;i++){
    str[i*2+1]='.';
    scanf(" %c",&str[i*2+2]);
    str[i*2+3]='.';
  }
  str[N*2+2]='$';
  //Use Manacher's algorithm to find all palindromic substrings
  int l=1,r=1;
  for(int i=1;i<N*2+2;i++){
    pal[i]=std::min(pal[l+r-i],r-i);
    while(str[i-pal[i]-1]==str[i+pal[i]+1]){
      pal[i]++;
    }
    if(i+pal[i]>r){
      l=i-pal[i];
      r=i+pal[i];
    }
    //decrease rcenter[i-pal[i],i-1] to i
    setrcenter.push_back({i,i-pal[i],i-1});
    //increase lcenter[i+1,i+pal[i]] to i
    setlcenter.push_back({i,i+1,i+pal[i]});
  }
  //For each letter, consider the minimal nontrivival palindromes that contain it
  //It either begins at the letter, ends at the letter, or is a three-character string centered at the letter
  //We explicitly find the minimum ones of the first two types
  
  //Range min/max assignments in bulk:
  //Each set element is erased once overall
  {
    std::set<int> unused;
    for(int i=1;i<=N*2+1;i++){
      rcenter[i]=INF;
      unused.insert(i);
    }
    std::sort(setrcenter.begin(),setrcenter.end());
    for(auto action:setrcenter){
      int X=action[0];
      int L=action[1],R=action[2];
      for(auto it=unused.lower_bound(L);it!=unused.end()&&*it<=R;it=unused.lower_bound(L)){
	rcenter[*it]=X;
	unused.erase(it);
      }
    }
  }
  {
    std::set<int> unused;
    for(int i=1;i<=N*2+1;i++){
      lcenter[i]=-INF;
      unused.insert(i);
    }
    std::sort(setlcenter.begin(),setlcenter.end());
    std::reverse(setlcenter.begin(),setlcenter.end());
    for(auto action:setlcenter){
      int X=action[0];
      int L=action[1],R=action[2];
      for(auto it=unused.lower_bound(L);it!=unused.end()&&*it<=R;it=unused.lower_bound(L)){
	lcenter[*it]=X;
	unused.erase(it);
      }
    }
  }
  std::vector<std::vector<std::pair<int,int> > > delta(N+1);
  for(int i=0;i<N;i++){
    //Find other end of minimal palindromes ending/starting at ith letter
    int l=std::max(-1,(lcenter[i*2+2]-2)-i);
    int r=std::min(N,(rcenter[i*2+2]-2)-i);
    //If i is taken, must also take l or r
    //mark all forbidden substrings
    delta[i].push_back({l+1,-1});
    delta[i].push_back({i+1,1});
    delta[r].push_back({l+1,1});
    delta[r].push_back({i+1,-1});
    //If i is the center of a nontrivial palindrome, we also have the option of taking i-1 and i+1 instead
    //unmark no longer forbidden substrings
    if(pal[i*2+2]>1){
      delta[i+1].push_back({l+1,1});
      delta[i+1].push_back({i,-1});
      delta[r].push_back({l+1,-1});
      delta[r].push_back({i,1});
    }
  }
  build(1,0,N);
  long long ans=0;
  for(int i=0;i<N;i++){
    for(auto change:delta[i]){
      update(1,0,N,0,change.first,change.second);
    }
    ans+=combine(Node(0,0),query(1,0,N,0,i)).cnt;
  }
  printf("%I64d\n",ans);
}