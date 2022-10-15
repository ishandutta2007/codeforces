#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long long ll;

const int N=2000+7;
const int M=(int)1e5;
int n,m,deg[N],sol[M],v1[M],v2[M];
int lim;
bool is_taken[N][N];
int vec[N][N];
int eid[N][N];

void set_edge(int i,int c){
  assert(0<=i&&i<m);
  int a=v1[i],b=v2[i];

  assert(0<=a&&a<n);
  assert(0<=b&&b<n);
  assert(0<=c&&c<lim);

  assert(!is_taken[a][c]);
  assert(!is_taken[b][c]);

  assert(sol[i]==0);

  eid[a][c]=i;
  eid[b][c]=i;

  vec[a][c]=b;
  vec[b][c]=a;
  is_taken[a][c]=is_taken[b][c]=1;
  sol[i]=c;
}

void del_edge(int i,int c){
  assert(0<=i&&i<m);
  int a=v1[i],b=v2[i];

  assert(0<=a&&a<n);
  assert(0<=b&&b<n);
  assert(0<=c&&c<lim);

  assert(is_taken[a][c]);
  assert(is_taken[b][c]);

  assert(sol[i]==c);

  eid[a][c]=0;
  eid[b][c]=0;

  vec[a][c]=0;
  vec[b][c]=0;
  is_taken[a][c]=is_taken[b][c]=0;
  sol[i]=0;
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif

  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  {
    int n1,n2;
    cin>>n1>>n2>>m;
    n=n1+n2;
    for (int i=0;i<m;i++){
      cin>>v1[i];
      cin>>v2[i];
      v2[i]+=n1;
      v1[i]--;
      v2[i]--;

      assert(0<=v1[i]&&v1[i]<n);
      assert(0<=v2[i]&&v2[i]<n);

      deg[v1[i]]++;
      deg[v2[i]]++;
    }
  }

  lim=*max_element(deg,deg+n);
  assert(lim<N);


  for(int i=0;i<m;i++){
    int a=v1[i];
    int b=v2[i];


    int ucol=-1;
    for (int c=0;c<lim;c++){
      if(!is_taken[a][c]&&!is_taken[b][c]){
        ucol=c;
        break;
      }
    }
    if(ucol!=-1){
      set_edge(i,ucol);
      continue;
    }
    assert(ucol==-1);
    int c1=-1,c2=-1;


    for (int c=0;c<lim;c++){
      if(!is_taken[a][c]){
        c2=c;
      }
      if(!is_taken[b][c]){
        c1=c;
      }
    }
    assert(c1!=-1);
    assert(c2!=-1);

    vector<int> path,eids;
    path.push_back(a);
    path.push_back(b);
    eids.push_back(i);

    while(1){
      if((int)path.size()%2==0){
        /// search for c2
        if(!is_taken[path.back()][c2]){
          break;
        }
        eids.push_back(eid[path.back()][c2]);
        path.push_back(vec[path.back()][c2]);
      }else{
        /// search for c1

        if(!is_taken[path.back()][c1]){
          break;
        }
        eids.push_back(eid[path.back()][c1]);
        path.push_back(vec[path.back()][c1]);
      }
    }
    assert((int)eids.size()==(int)path.size()-1);
    assert(!eids.empty());

    for (int i=1;i<(int)eids.size();i++){
      del_edge(eids[i],((i%2==1)?c2:c1));
    }

    for (int i=0;i<(int)eids.size();i++){
      set_edge(eids[i],((i%2==0)?c2:c1));
    }
  }
  cout<<lim<<"\n";
  for (int i=0;i<m;i++){
    cout<<sol[i]+1<<" ";
  }
  cout<<"\n";
}