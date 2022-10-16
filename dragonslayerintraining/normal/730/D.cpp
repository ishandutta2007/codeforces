#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll N,R;
ll L[200001];
ll T[200001];
vector<ll>ans;
ll potCnt=0;

int main(){
  cin>>N>>R;
  for (int i=0;i<N;i++)
    cin>>L[i];
  for (int i=0;i<N;i++)
    cin>>T[i];
  ll dur=0,TIME=0; //time left on drink, current time
  for (int i=0;i<N;i++){
    if (L[i]>T[i]){
      cout<<-1<<endl;
      return 0;
    }
    if (dur>=L[i]){
      dur-=L[i];
      TIME+=L[i];
      continue;
    }
    if (dur+(L[i]-dur)*2<=T[i]){
      TIME+=dur+(L[i]-dur)*2;
      dur=0;
      continue;
    }
    if (dur>0){
      T[i]-=dur;
      L[i]-=dur;
      TIME+=dur;
      dur=0;
    }
    //need to pot up
    ll needSpeed=L[i]*2-T[i];
    TIME+=(L[i]-needSpeed)*2;
    ll num=needSpeed/R;
    potCnt+=num;
    if ((int)ans.size()+num<=100000){
      for (int j=0;j<num;j++){
	ans.push_back(TIME);
	TIME+=R;
      }
    }
    needSpeed-=num*R;
    if (needSpeed>0){
      ans.push_back(TIME);
      potCnt++;
      dur+=R-needSpeed;
      TIME+=needSpeed;
    }
  }
  if (potCnt>100000){
    cout<<potCnt<<endl;
    return 0;
  }
  cout<<ans.size()<<endl;
  for (ll X:ans)
    cout<<X<<' ';
  cout<<endl;
  return 0;
}