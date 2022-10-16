#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
#include <tuple>

const int INF=1e9+7;

void setmax(int& x,int y){x=std::max(x,y);}

const int TRIE_MAX=805*10*2;
struct Trie{
  int chd[10];
  int suffix;
  int here;
  int add;
  Trie():suffix(0),here(0),add(0){
    std::fill(chd,chd+10,0);
  }
}trie[TRIE_MAX];
int trie_size=1;
std::vector<int> trie_ord;

std::vector<int> reduce[2005];

int dp[2005][TRIE_MAX];
int ok[2005][TRIE_MAX];//if possible to reach maximum from this state

int getchild(int node,int c){
  assert(c>=0&&c<10);
  if(!trie[node].chd[c]){
    assert(trie_size<TRIE_MAX);
    trie[node].chd[c]=trie_size++;
  }
  return trie[node].chd[c];
}

std::string L,R;

//lf: if prefix is still matching L (else strictly greater)
//rf: if prefix is still matching R (else strictly less)
void dfs_build(int index,int prefix,bool lf,bool rf){
  if(index==R.size()||(!lf&&!rf)){
    trie[prefix].here++;
    reduce[R.size()-index].push_back(prefix);
    return;
  }
  for(char d='0';d<='9';d++){
    if(lf&&L[index]>d) continue;
    if(rf&&R[index]<d) continue;
    dfs_build(index+1,(prefix||d!='0')?getchild(prefix,d-'0'):0,lf&&(L[index]==d),rf&&(R[index]==d));
  }
}

void aho_corasick(){
  trie_ord.push_back(0);
  for(int c=0;c<10;c++){
    if(trie[0].chd[c]){
      trie_ord.push_back(trie[0].chd[c]);
    }
  }
  for(int i=1;i<trie_size;i++){
    int node=trie_ord[i];
    for(int c=0;c<10;c++){
      int fall=trie[trie[node].suffix].chd[c];
      int& child=trie[node].chd[c];
      if(child){
	trie[child].suffix=fall;
	trie_ord.push_back(child);
      }else{
	child=fall;
      }
    }
  }
}

void compute_add(){
  for(int i=1;i<trie_size;i++){
    int node=trie_ord[i];
    trie[node].add=trie[node].here+trie[trie[node].suffix].add;
  }
}

int main(){
  std::cin>>L>>R;
  while(L.size()<R.size()){
    L="0"+L;
  }
  dfs_build(0,0,true,true);
  aho_corasick();
  int N;
  std::cin>>N;
  for(int i=0;i<=N;i++){
    for(int s=0;s<trie_size;s++){
      dp[i][s]=-INF;
    }
  }
  dp[0][0]=0;
  for(int i=R.size();i>N;i--){
    for(int s:reduce[i]){
      trie[s].here--;
    }
  }
  compute_add();
  for(int i=0;i<N;i++){
    for(int s:reduce[N-i]){
      trie[s].here--;
    }
    compute_add();
    for(int s=0;s<trie_size;s++){
      for(int c=0;c<10;c++){
	int s2=trie[s].chd[c];
	setmax(dp[i+1][s2],dp[i][s]+trie[s2].add);
      }
    }
  }
  int best=0;
  for(int s=0;s<trie_size;s++){
    setmax(best,dp[N][s]);
  }
  for(int s=0;s<trie_size;s++){
    if(dp[N][s]==best){
      ok[N][s]=1;
    }
  }
  for(int i=N-1;i>=0;i--){
    for(int s=0;s<trie_size;s++){
      for(int c=0;c<10;c++){
	int s2=trie[s].chd[c];
	if(dp[i+1][s2]==dp[i][s]+trie[s2].add){
	  ok[i][s]|=ok[i+1][s2];
	}
      }
    }
    for(int s:reduce[N-i]){
      trie[s].here++;
    }
    compute_add();
  }
  printf("%d\n",best);
  int s=0;
  for(int i=0;i<N;i++){
    for(int s:reduce[N-i]){
      trie[s].here--;
    }
    compute_add();
    assert(ok[i][s]);
    for(int c=0;c<10;c++){
      int s2=trie[s].chd[c];
      if(dp[i+1][s2]==dp[i][s]+trie[s2].add&&ok[i+1][s2]){
	printf("%d",c);
	s=s2;
	break;
      }
    }
  }
  printf("\n");
  return 0;
}