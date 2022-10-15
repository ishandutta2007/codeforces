#include <bits/stdc++.h>

using namespace std;

bool strict_smaller(string s,string t){
  for (int i=0;i<min((int)s.size(),(int)t.size());i++){
    if(s[i]!=t[i])return s[i]<t[i];
  }
  return 0;
}

string gessso(string s){
  sort(s.begin(),s.end());
  return s;
}

#define int long long

const int N=(int)1e5+77;
int n;
int tree[N];
vector<int>wheres[26];

void add(int i,int x){
  assert(1<=i&&i<=n);
  while(i<=n){
    tree[i]+=x;
    i+=i&(-i);
  }
}

int get(int i){
  assert(1<=i&&i<=n);
  int sol=0;
  while (i){
    sol+=tree[i];
    i-=i&(-i);
  }
  return sol;
}

//mt19937 rng((long long)(new char));
mt19937 rng(777);

int smart(string s,string t){
  n=(int)s.size();
  assert((int)s.size()==n);
  assert((int)t.size()==n);
  if(!(strict_smaller(gessso(s),t))){
    return -1;
  }
  for (int i=0;i<=n+7;i++)tree[i]=0;
  for (int i=0;i<26;i++)wheres[i].clear();
  for (int i=0;i<n;i++){
    wheres[s[i]-'a'].push_back(i+1);
  }
  for (int i=0;i<26;i++)reverse(wheres[i].begin(),wheres[i].end());
  int sol=(int)1e18,cost=0;
  for (int f=1;f<=n;f++){
    int current=t[f-1]-'a';
    for (int ch=0;ch<current;ch++){
      if(!wheres[ch].empty()){
        int first=wheres[ch].back();
        sol=min(sol,cost+first-get(first)-1);
      }
    }
    if (wheres[current].empty())break;

    int first=wheres[current].back();
    wheres[current].pop_back();
    cost+=first-get(first)-1;
    add(first,+1);
  }
  assert(sol!=(int)1e18);
  return sol;
}

int dumb(string s,string t){
  map<string,int>cost;
  queue<string>q;
  q.push(s);
  cost[s]=0;
  while(!q.empty()){
    string cur=q.front();
    q.pop();
    for (int i=0;i<(int)cur.size()-1;i++){
      string cop=cur;
      swap(cop[i],cop[i+1]);
      if(!cost.count(cop)){
        cost[cop]=1+cost[cur];
        q.push(cop);
      }
    }
  }
  int sol=(int)1e18;
  for (auto &it:cost){
    if(it.first<t)sol=min(sol,it.second);
  }
  if (sol==(int)1e18)sol=-1;
  return sol;
}

string gn(int len,int alphabet){
  string sol;
  for (int i=1;i<=len;i++){
    sol+=(char)('a'+rng()%alphabet);
  }
  return sol;
}

signed main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  //freopen("input","r",stdin);


  /*int lmax=5;
  int alphabet=10;
  for (int it=1;1;it++){
    int len=rng()%lmax+1;
    string s=gn(len,alphabet);
    string t=gn(len,alphabet);

    int x=dumb(s,t);
    int y=smart(s,t);
    if(it%1000==0){
      cout<<"ok "<<it<<"\n";
    }
    if(x!=y){

      cout<<"error : "<<x<<" "<<y<<"\n";
      cout<<s<<"\n";
      cout<<t<<"\n";
      exit(0);
    }
  }*/

  int tests;
  cin>>tests;
  while (tests--)
  {
    string s,t;
    cin>>n>>s>>t;
    cout<<smart(s,t)<<"\n";
  }
}