#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

struct SuffixAutomaton{
  struct State{
    std::map<char,int> next;
    int link;
    int len;
    int occur;
    int vis;
    State(int len):link(-1),len(len),occur(1),vis(0){
    }
  };
  std::vector<struct State> states;
  int last;
  SuffixAutomaton():last(0){
    states.emplace_back(0);
  }
  void append(char c){
    int curr=states.size();
    states.emplace_back(states[last].len+1);
    for(;last!=-1&&!states[last].next.count(c);last=states[last].link){
      states[last].next[c]=curr;
    }
    if(last==-1){
      states[curr].link=0;
    }else{
      int q=states[last].next[c];
      if(states[q].len==states[last].len+1){
	states[curr].link=q;
      }else{
	int clone=states.size();
	states.push_back(states[q]);
	states[clone].len=states[last].len+1;
	states[clone].occur=0;
	states[curr].link=states[q].link=clone;
	for(;last!=-1&&states[last].next[c]==q;last=states[last].link){
	  states[last].next[c]=clone;
	}
      }
    }
    last=curr;
  }
  void finalize(){
    std::vector<std::pair<int,int> > ord;
    for(int i=1;i<states.size();i++){
      ord.emplace_back(states[i].len,i);
    }
    std::sort(ord.begin(),ord.end());
    std::reverse(ord.begin(),ord.end());
    for(auto it:ord){
      int i=it.second;
      states[states[i].link].occur+=states[i].occur;
    }
  }
};

char str[1000005];

int border[1000005];

int main(){
  scanf("%s",str);
  struct SuffixAutomaton sa;
  for(int i=0;str[i];i++){
    sa.append(str[i]);
  }
  sa.finalize();
  /*
  for(int i=0;i<sa.states.size();i++){
    printf("State %d (len=%d) (cnt=%d) => %d\n",i,sa.states[i].len,sa.states[i].occur,sa.states[i].link);
    for(auto it:sa.states[i].next){
      printf(" =%c>%d\n",it.first,it.second);
    }
  }
  */
  /*
  while(true){
    scanf("%s",str);
    int curr=0;
    for(int i=0;str[i];i++){
      if(!sa.states[curr].next.count(str[i])){
	curr=-1;
	break;
      }
      curr=sa.states[curr].next[str[i]];
    }
    printf("%d\n",(curr==-1)?0:sa.states[curr].occur);
  }
  */
  int Q;
  scanf("%d",&Q);
  for(int q=1;q<=Q;q++){
    scanf("%s",str);
    int len=strlen(str);
    for(int i=len;i<len*2-1;i++){
      str[i]=str[i-len];
    }
    int s=0;
    int match=0;
    int ans=0;
    for(int i=0;i<len*2-1;i++){
      while(s!=-1&&!sa.states[s].next.count(str[i])){
	s=sa.states[s].link;
      }
      if(s==-1){
	s=0;
	match=0;
      }else{
	match=std::min(match,sa.states[s].len);
	s=sa.states[s].next[str[i]];
	match++;
      }
      if(match>=len){
	while(sa.states[sa.states[s].link].len>=len){
	  s=sa.states[s].link;
	}
	if(sa.states[s].vis==q) break;
	sa.states[s].vis=q;
	ans+=sa.states[s].occur;
	//printf("i=%d: s=%d +%d\n",i,s,sa.states[s].occur);
      }
    }
    printf("%d\n",ans);
  }
  
  
  return 0;
}