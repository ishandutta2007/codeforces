#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <deque>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 2001001001
#define MOD 1000000007

int N,M;
string S[101];
int arr[101];
bool del[101];

bool match(string s1, string s2){
  if (s1.length()!=s2.length())
    return false;
  for (int i=0;i<(int)s1.length();i++)
    if (s1[i]!='?' && s1[i]!=s2[i])
      return false;
  return true;
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N>>M;
  for (int i=0;i<N;i++)
    cin>>S[i];
  for (int i=0;i<M;i++){
    cin>>arr[i];
    arr[i]--;
    del[arr[i]]=true;
  }
  for (int i=0;i<M;i++)
    if (S[arr[0]].length()!=S[arr[i]].length()){
      cout<<"No"<<endl;
      return 0;
    }
  int len=S[arr[0]].length();
  string ans;
  for (int i=0;i<len;i++){
    char c=S[arr[0]][i];
    bool bad=false;
    for (int j=0;j<M;j++)
      if (S[arr[j]][i]!=c)
	bad=true;
    if (bad)
      ans+="?";
    else
      ans+=c;
  }
  for (int i=0;i<N;i++)
    if (match(ans,S[i])!=del[i]){
      cout<<"No"<<endl;
      return 0;
    }
  cout<<"Yes"<<endl;
  cout<<ans<<endl;
  return 0;
}