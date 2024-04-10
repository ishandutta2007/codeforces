#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;

set<pair<int,int>> v,mark;
int T,a,b,ok;
string s;

bool obstacle(int i,int j){
  return mark.find(make_pair(i,j))!=mark.end();
}

void go(char t){
  if(t=='L'&&!obstacle(a-1,b))--a;
  else if(t=='R'&&!obstacle(a+1,b))++a;
  else if(t=='U'&&!obstacle(a,b+1))++b;
  else if(t=='D'&&!obstacle(a,b-1))--b;
}

int main() {
  scanf("%d",&T);
  while(T--){
    ok=0;
    mark.clear();
    v.clear();
    cin >> s;
    a=0;b=0;
    for(int i=0;i<s.size();++i){
      v.insert(make_pair(a+1,b));
      v.insert(make_pair(a-1,b));
      v.insert(make_pair(a,b-1));
      v.insert(make_pair(a,b+1));
      go(s[i]);
    }
    if(!a&&!b){
      puts("99999999 99999999");
      continue;
    }
    //cout << " Case " << s << endl;
    for(set<pair<int,int>>::iterator it=v.begin(); it!=v.end(); ++it){
      a=b=0;
      mark.clear();
      pair<int,int> p = *it;
      if(!p.first&&!p.second)continue;
      mark.insert(p);
      // cout << "Mark " << p.first << ' ' << p.second << endl;
      for(int i=0; i<s.size(); ++i){
        go(s[i]);
      }
      if(!a&&!b){
        printf("%d %d\n",p.first,p.second);
        ok=1;
        break;
      }
    }
    if(!ok)puts("0 0");
  }
}