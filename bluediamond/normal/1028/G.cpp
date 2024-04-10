#include <bits/stdc++.h>

using namespace std;
#define int long long

bool home = 1;


const int QMAX=(int)1e4+7;
const int QLIM=7;
int maxlen[QMAX][QLIM];

int compute(int start,int qs){
  start=min(start,QMAX-7);
  assert(1<=start&&start<=QMAX-7);
  assert(0<=qs&&qs<=5);

  if(maxlen[start][qs]!=-1) return maxlen[start][qs];
  int& sol=maxlen[start][qs];

  if(qs==0){
    sol=0;
    return sol;
  }

  int place=start;
  int current=start;

  for(int iter=1;iter<=place+1;iter++){

    current=current+compute(current,qs-1)+1;
    if(iter==place+1)current--;
  }



  sol=current-start;
  return sol;
}

vector<int> place(int start,int qs){
  compute(start,qs);

  int len=compute(start,qs);

  int rlstart=start,dif=0;
  start=min(start,QMAX-7);
  dif=rlstart-start;

  assert(1<=start&&start<=QMAX-7);
  assert(1<=qs&&qs<=5);


  int place=start;
  int current=start;

  vector<int> sol;


  for(int iter=1;iter<=place+1;iter++){
    if(iter<=place){
      sol.push_back(dif+current+compute(current,qs-1));
    }
    current=current+compute(current,qs-1)+1;
  }



  return sol;
}

void logic(int start,int finito,int qs){
  if(home){
    cout<<"\t\t\t\t\tqs = "<<qs<<"\n";
    cout<<"\t\t\t\t\tst = "<<start<<"\n";
    cout<<"\t\t\t\t\tdr = "<<finito<<"\n";
  }
  assert(1<=qs&&qs<=5);
  assert(compute(start,qs)>=finito-start);

  vector<int> sol=place(start,qs);
  cout<<(int)sol.size()<<" ";
  for(auto&x:sol){
    cout<<x<<" ";
  }
  cout<<endl;
  int code;
  cin>>code;
  if(code==-2) assert(0);
  if(code==-1) exit(0);
  assert(0<=code&&code<=(int)sol.size());

  int st,dr;
  if(code==0){
    st=start;
  }else{
    st=sol[code-1]+1;
  }
  if(code==(int)sol.size()){
    dr=finito;
  }else{
    dr=sol[code]-1;
  }
  logic(st,dr,qs-1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  /**if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }**/

  for(int i=0;i<QMAX;i++){
    for(int j=0;j<QLIM;j++){
      maxlen[i][j]=-1;
    }
  }



  logic(1,10004205361450474,5);


  return 0;
}