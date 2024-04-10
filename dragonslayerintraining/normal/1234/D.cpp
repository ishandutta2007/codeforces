#include <iostream>
#include <map>
#include <set>

std::map<char,std::set<int> > where;
std::string S;

int main(){
  std::cin>>S;
  for(int i=0;i<S.size();i++){
    where[S[i]].insert(i);
  }
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int T;
    scanf("%d",&T);
    if(T==1){
      int pos;
      char c;
      scanf("%d %c",&pos,&c);
      pos--;
      where[S[pos]].erase(pos);
      S[pos]=c;
      where[S[pos]].insert(pos);
    }else{
      int L,R;
      scanf("%d %d",&L,&R);
      L--;
      int cnt=0;
      for(char c='a';c<='z';c++){
	auto it=where[c].lower_bound(L);
	if(it!=where[c].end()&&*it<R){
	  cnt++;
	}
      }
      printf("%d\n",cnt);
    }
  }
}