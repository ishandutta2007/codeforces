#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool home = 1;
bool wannap = 0;

struct ve{
  int x;
  int y;
};

bool operator < (ve a,ve b){
  if(a.x!=b.x)return a.x<b.x;
  return a.y<b.y;
}

struct Rect{
  int xmin,xmax;
  int ymin,ymax;
} rect;

struct Line{
  bool onx;
  int x;
  int ymin;
  int ymax;
  bool valid;
  int dirspec;
};

Line getline(bool onx,int x,int ymin,int ymax,int dirspec){
  Line l;
  l.valid=1;
  if(ymin>=ymax){
    l.valid=0;
    return l;
  }
  l.onx=onx;
  l.x=x;
  l.ymin=ymin;
  l.ymax=ymax;
  l.dirspec=dirspec;
  return l;
}


const int N=(int)15000+7;
ve p1,p2;
int n;
ve p[N];
vector<Line> lines;


Line iisection(ve f,ve s){
  Line bad;
  bad.valid=0;
  assert(f.x==s.x||f.y==s.y);
  assert(f.x!=s.x||f.y!=s.y);
  if(f.x==s.x){
    assert(f.y!=s.y);
    int x=f.x;
    int ymin=min(f.y,s.y),ymax=max(f.y,s.y);
    if(rect.xmin<x&&x<rect.xmax){
      return getline(1,x,max(rect.ymin,ymin),min(rect.ymax,ymax),(ymin==f.y));
    }else{
      return bad;
    }
  }else{
    assert(f.y==s.y);
    int y=f.y;
    int xmin=min(f.x,s.x),xmax=max(f.x,s.x);
    if(rect.ymin<y&&y<rect.ymax){
      return getline(0,y,max(rect.xmin,xmin),min(xmax,rect.xmax),(xmin==f.x));
    }else{
      return bad;
    }
  }
}

map<ve,bool> vis;

void ps(ve a,ve b){
  cout<<"Segment "<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<"\n";
}

struct Edge{
  ve v1;
  ve v2;
  int code;
};

vector<Edge> edges;

void addLine(Line l){
  assert(l.valid);
  int x1=l.x,x2=l.x,y1=l.ymin,y2=l.ymax;
  if(!l.onx){
    swap(x1,y1);
    swap(x2,y2);
  }
  vis[{x1,y1}]=0;
  vis[{x2,y2}]=0;
//  ps({x1,y1},{x2,y2});
  edges.push_back({{x1,y1},{x2,y2},l.dirspec});
}

void print(Line l){
  assert(l.valid);
  int x1=l.x,x2=l.x,y1=l.ymin,y2=l.ymax;
  if(!l.onx){
    swap(x1,y1);
    swap(x2,y2);
  }
  cout<<"Segment "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
}


void prect(Rect rect){
  ve v1={rect.xmin,rect.ymin};
  ve v2={rect.xmax,rect.ymin};
  ve v3={rect.xmax,rect.ymax};
  ve v4={rect.xmin,rect.ymax};
  ps(v1,v2);
  ps(v2,v3);
  ps(v3,v4);
  ps(v4,v1);
}


int getLeft(int k){return (k+1)%4;}/// may wanna swap it with right
int getRight(int k){return (k+3)%4;} /// may wanna swap it with left
int getFront(int k){return k%4;}
int getBack(int k){return (k+2)%4;}

int getdir(ve a,ve b){/// may also wanna permute this guys
  if(a.y==b.y&&a.x<b.x)return 0;
  if(a.x==b.x&&a.y<b.y) return 1;
  if(a.y==b.y&&a.x>b.x)return 2;
  if(a.x==b.x&&a.y>b.y) return 3;
  assert(0);
}

map<ve,ve> nxt[4];
map<ve,bool> ispec[4];
map<ve,bool> ivalid[4];

vector<ve> cur;
set<ve> act;
map<ve,int> when;

bool good;

void expl(ve p,int k){
  if(act.count(p)){
    assert(when.count(p));
    cur.erase(cur.begin(),cur.begin()+when[p]);
    return;
  }
 // cout<<" : "<<p.x<<" "<<p.y<<"\n";
  when[p]=(int)cur.size();
  act.insert(p);
  cur.push_back(p);
  vector<int> tries;
  tries.push_back(getLeft(k));
  tries.push_back(getRight(k));
  tries.push_back(getFront(k));
  for(auto&tr:tries){
    if(ivalid[tr][p]){
    //  cout<<"aici\n";
      good|=ispec[tr][p];
      ivalid[tr][p]=0;
      expl(nxt[tr][p],tr);
      return;
    }
  }
  cur.clear();
  return;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  wannap=1;


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }
 /// freopen("output","w",stdout);


  cin>>p1.x>>p1.y>>p2.x>>p2.y;
  rect.xmax=max(p1.x,p2.x);
  rect.xmin=min(p1.x,p2.x);
  rect.ymax=max(p1.y,p2.y);
  rect.ymin=min(p1.y,p2.y);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
  }
  if(home&&1){
    prect(rect);
  }
  p[n]=p[0];
  for(int i=0;i<n;i++){
    if(home&&0){
      cout<<"Segment "<<p[i].x<<" "<<p[i].y<<" "<<p[i+1].x<<" "<<p[i+1].y<<"\n";
    }
  }


  bool strict_outside=0;
  bool strict_inside=0;



  for(int i=0;i<n;i++){
    strict_inside|=(rect.xmin<p[i].x&&p[i].x<rect.xmax&&rect.ymin<p[i].y&&p[i].y<rect.ymax);
    strict_outside|=(p[i].x<rect.xmin||rect.xmax<p[i].x||p[i].y<rect.ymin||rect.ymax<p[i].y);
  }
  if(strict_outside==0||n==4){
    cout<<"1\n";
    return 0;
  }
  /*if(strict_inside==0){
    cout<<"0\n";
    if(n==5000){
      cout<<"what???\n";
    exit(0);
      assert(0);
    }
    return 0;
  }*/

  for(int i=0;i<n;i++){
    Line l=iisection(p[i],p[i+1]);
    if(l.valid){
      lines.push_back(l);
    }
  }

  for(auto&l:lines){
    addLine(l);
  }

  ///exit(0);
  if(home&&wannap&&0){
    for(auto&l:lines){
      print(l);
    }
    cout<<"done printing segs\n######################\n";
  }

  set<ve> spec;
  spec.insert({rect.xmin,rect.ymin});
  spec.insert({rect.xmin,rect.ymax});
  spec.insert({rect.xmax,rect.ymin});
  spec.insert({rect.xmax,rect.ymax});


  for(auto&it:vis){
    ve v=it.first;
    if(v.x==rect.xmin||v.x==rect.xmax||v.y==rect.ymin||v.y==rect.ymax){
      spec.insert(v);
    }
  }

  map<int,vector<int>> onx,ony;

  for(auto&it:spec){
    onx[it.x].push_back(it.y);
    ony[it.y].push_back(it.x);
  }

  for(auto&it:onx){
    if(it.first==rect.xmin||it.first==rect.xmax){
      vector<int> ys=it.second;
      for(int j=1;j<(int)ys.size();j++){
        edges.push_back({{it.first,ys[j-1]},{it.first,ys[j]},-1});
      }
    }
  }


  for(auto&it:ony){
    if(it.first==rect.ymin||it.first==rect.ymax){
      vector<int> xs=it.second;
      for(int j=1;j<(int)xs.size();j++){
        edges.push_back({{xs[j-1],it.first},{xs[j],it.first},-1});
      }
    }
  }


  if(home&&0){
    for(auto&it:spec){
      cout<<"Point "<<it.x<<" "<<it.y<<"\n";
    }
  }

  for(auto&it:edges){
   // ps(it.v1,it.v2);
  }

  for(auto&it:edges){
    for(int S=0;S<2;S++){
      if(home&&wannap&&S==0){
        ps(it.v1,it.v2);
      }
      int dir=getdir(it.v1,it.v2);
      nxt[dir][it.v1]=it.v2;
      ispec[dir][it.v1]=(S==(1^it.code)); /// or (1^it.code)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      ivalid[dir][it.v1]=1;
      swap(it.v1,it.v2);
    }
  }

  for(auto&it:spec){
    vis[it]=0;
  }
  int ko=0;
  int cnt_good=0,cnt_bad=0;
  for(auto&it:vis){
    ve v=it.first;

    for(int k=0;k<4;k++){
      if(ivalid[k][v]){
        act.clear();
        cur.clear();
        when.clear();
        act.insert(v);
        when[v]=0;
        good=0;
        ivalid[k][v]=0;
        cur.push_back(v);
        expl(nxt[k][v],k);
        if(cur.empty()){
          continue;
        }
        cnt_good+=good;
        cnt_bad+=!good;
        int ind=0;
        if(home){
          for(auto&it:cur){
            cout<<it.x<<" "<<it.y<<" "<<(char)(ko+'A')<<++ind<<"\n";
          }

          cout<<"done "<<(char)(ko+'A')<<"\n";

          cout<<"\n";
        }
        ko++;
      }
    }
  }

  cout<<cnt_good;
 /// cout<<cnt_good<<" "<<cnt_bad<<"\n";
  return 0;
}