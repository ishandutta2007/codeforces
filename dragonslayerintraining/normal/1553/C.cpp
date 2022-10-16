#include <iostream>

int kicks(std::string S){
  int a_left=5,b_left=5;
  int a_score=0,b_score=0;
  for(int i=0;i<S.size();i++){
    if(i%2==0){
      a_left--;
      a_score+=(S[i]=='1');
    }else{
      b_left--;
      b_score+=(S[i]=='1');
    }
    if(a_score>b_score+b_left||b_score>a_score+a_left){
      return i+1;
    }
  }
  return 10;
}

void solve(){
  std::string S;
  std::cin>>S;
  std::string a,b;
  for(int i=0;i<10;i++){
    char c=S[i];
    a.push_back((c=='?')?'0'+(i%2):c);
    b.push_back((c=='?')?'1'-(i%2):c);
  }
  printf("%d\n",std::min(kicks(a),kicks(b)));
}

int main(){
  int T;
  std::cin>>T;
  while(T--){
    solve();
  }
}