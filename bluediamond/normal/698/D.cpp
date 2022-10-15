#include <bits/stdc++.h>

using namespace std;

bool home = 1;

#define int long long

struct pt{
  int x,y;

};

pt operator - (pt a,pt b){
  a.x-=b.x;
  a.y-=b.y;
  return a;
}


int dot(pt a,pt b){
  return a.x*b.x+a.y*b.y;
}

int cross(pt a,pt b){
  return a.x*b.y-a.y*b.x;
}


bool operator < (pt a,pt b){
  if(a.x!=b.x)return a.x<b.x;
  return a.y<b.y;
}

const int K=7;
const int N=1000+7;
int k,n,bef[K][N];

bool visk[K];
bool vis[N];
bool inside[N];


void print(vector<int>v){
  cout<<" ---> ";
  for (auto &x:v){
    cout<<x<< " ";
  }
  cout<<"\n";
}

bool tr(vector<int> need){
  if(need.empty())return 1;
  vector<int>free;
  for (int j=0;j<k;j++){
    if(visk[j]==0)free.push_back(j);
  }
  if((int)need.size()>(int)free.size())return 0;
  int i=need.back();
  need.pop_back();
  for (auto &j:free){
    visk[j]=1;
    vis[i]=1;
    int cur=bef[j][i];
    vector<int>bubu;
    while (cur&&(int)need.size()<=k){
      if (inside[cur]==0&&vis[cur]==0){
        inside[cur]=1;
        need.push_back(cur);
        bubu.push_back(cur);
      }
      cur=bef[j][cur];
    }
    if(tr(need)){
    for (auto &cur:bubu){
      inside[cur]=0;
    }    vis[i]=0;
    visk[j]=0;return 1;
    }
    for (auto &cur:bubu){
      need.pop_back();
      inside[cur]=0;
    }
    vis[i]=0;
    visk[j]=0;
  }
  return 0;
}

vector<pt> b;
pt oo;

bool cmp(int i,int j){
  return dot(b[i-1]-oo,b[i-1]-oo)<dot(b[j-1]-oo,b[j-1]-oo);
}


bool operator == (pt a,pt b){
  return (abs(a.x-b.x)==0&abs(a.y-b.y)==0);
}

pt ff;



int gnum(pt a,pt b){
  int s1=0,s2=0;
  if(a.x<b.x)s1=0;
  if(a.x==b.x)s1=1;
  if(a.x>b.x)s1=2;
  if(a.y<b.y)s2=0;
  if(a.y==b.y)s2=1;
  if(a.y>b.y)s2=2;
  return s1*3+s2;
}


bool cox(int i,int j){
  if(gnum(b[i-1],ff)!=gnum(b[j-1],ff))return gnum(b[i-1],ff)<gnum(b[j-1],ff);
if(cross(b[i-1]-ff,b[j-1]-ff)!=0){
    pt aa=b[i-1]-ff;
    pt bb=b[j-1]-ff;
    return cross(b[i-1]-ff,b[j-1]-ff)>0;
    }
  return gnum(b[i-1],ff)<gnum(b[j-1],ff);
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>k>>n;
  vector<pt> a(k);
  b.resize(n);
  for (auto &p:a){int xx,yy;cin>>xx>>yy;p={xx,yy};}
  for (auto &p:b){int xx,yy;cin>>xx>>yy;p={xx,yy};}

  for (int i=0;i<k;i++) {
    vector<int> lol;
    for (int j=0;j<n;j++){
      lol.push_back({j+1});
     // cout<<norm(b[j]-a[i]).x<<" "<<norm(b[j]-a[i]).y<<"\n";
    }
    ff=a[i];
    sort(lol.begin(),lol.end(),cox);

    vector<int>bf;
    int l=0;
    while (l<n){
      int r=l;
      while(r+1<n&&cross(b[lol[r+1]-1]-ff,b[lol[r]-1]-ff)==0&&
            gnum(b[lol[r+1]-1],ff)==gnum(b[lol[r]-1],ff))
              r++;
      vector<int>v;
      for (int j=l;j<=r;j++)v.push_back(lol[j]);
      oo=a[i];
      sort(v.begin(),v.end(),cmp);
      /**for (auto &it:v){
        cout<<it<<" ";
      }
      cout<<"   ";**/
      for (int j=0;j<(int)v.size();j++){
        for (auto &jj:bf){
        int x1=b[jj-1].x-a[i].x;
        int x2=b[v[j]-1].x-a[i].x;

        int y1=b[jj-1].y-a[i].y;
        int y2=b[v[j]-1].y-a[i].y;
        if(x1*y2-x2*y1==0){
       //   cout<<"\n";
       //   cout<<"bad : "<<v[j]<<" vs "<<jj<<"\n";
          assert(min(x1,x2)<=0&&0<=max(x1,x2)&&min(y1,y2)<=0&&0<=max(y1,y2));

         //cout<<"bad : "<<
          assert(((b[jj-1].x<a[i].x)^(b[v[j]-1].x<a[i].x))==1||((b[jj-1].y<a[i].y)^(b[v[j]-1].y<a[i].y))==1);
        }

      }
      }
      for (int j=1;j<(int)v.size();j++){
        int x1=b[v[j-1]-1].x-a[i].x;
        int x2=b[v[j]-1].x-a[i].x;

        int y1=b[v[j-1]-1].y-a[i].y;
        int y2=b[v[j]-1].y-a[i].y;


       // cout<<": "<<x1*y2<<" " <<x2*y1<<"\n";
        assert(x1*y2-x2*y1==0);

        bef[i][v[j]]=v[j-1];
      }
      for (int j=l;j<=r;j++)bf.push_back(lol[j]);
      l=r+1;

    }
   // cout<<"\n";
  //  return 0;
  }

  int sol=0;
  for (int i=1;i<=n;i++){
    bool ok=0;
    for (int j=0;j<k&&ok==0;j++){
      visk[j]=vis[i]=1;
      vector<int>need;
      {
        int cur=bef[j][i];
        while(cur&&(int)need.size()<=k){
          inside[cur]=1;
          need.push_back(cur);
          cur=bef[j][cur];
        }
      }
      ok=tr(need);
      visk[j]=vis[i]=0;
      for (auto &cur:need){
        inside[cur]=0;
      }
     /// for (int it=0;it<k;it++)assert(visk[it]==0);
     /// for (int it=0;it<n;it++)assert(vis[it]==0);
     /// for (int it=0;it<n;it++)assert(inside[it]==0);
    }
    sol+=ok;
  }
  cout<<sol<<"\n";
  return 0;
}