#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long long ll;

int n;
ll m;

ll rep(ll x) {
  x%=m;
  if(x<0) x+=m;
  return x;
}

struct Frog{
  ll when_updated=-1;
  ll x;
  ll jump;
  int index;
};

bool cmpFrogX(Frog a,Frog b) {
  return a.x<b.x;
}

const int N=(int)1e5+7;
const ll INF=(ll)1e18+7;
Frog frogs[N];
int where[N];
set<int> rem_inds;

int ii;
ll ww;
ll iiww;


ll get_position(int i,ll when){

  assert(0<=i&&i<n);

  if(frogs[i].when_updated>when){
    assert(i==ii);
    assert(when==ww);

    return iiww;
  }

  assert(frogs[i].when_updated<=when);

  return rep(frogs[i].x+frogs[i].jump*((when-frogs[i].index+n)/n-(frogs[i].when_updated+n-frogs[i].index)/n));
}

void print_data(int i) {
  cout<<"data of "<<i<<" : "<<frogs[i].x<<" "<<frogs[i].jump<<"\n";
}

bool print;

ll when_intersect(int i,int j,ll when){

  /// when does i eat j?


  int dist_to_i=(frogs[i].index-when%n+n)%n;
  int dist_to_j=(frogs[j].index-when%n+n)%n;

  ll next_i=when+dist_to_i;

  assert(where[next_i%n]==i);

  if(print){
    cout<<"le : " <<frogs[i].when_updated<<" "<<frogs[j].when_updated<<" : "<<when<<"\n";
  }
  ll xi=get_position(i,when-1),jumpi=frogs[i].jump;
  ll xj=get_position(j,when-1),jumpj=frogs[j].jump;

  if(print){
    cout<<"le le\n";
  }
  ///cout<<" = "<<xi<<" and "<<xj<<"\n";

  assert(xi!=xj);

  assert(dist_to_i!=dist_to_j);


  if(dist_to_j<dist_to_i){
    ll from=xj,to=rep(xj+jumpj);
    if(jumpj>0){
      if(from<to){
        if(from<=xi&&xi<=to) return INF;
      }else{
        if(from<=xi||xi<=to) return INF;
      }
    }
    xj=rep(xj+jumpj);
  }



  if(xi>xj){
    xj+=m;
  }


  assert(xi<xj);

  /// i goes before j

  assert(xi<xj);


  ll distance=xj-xi;

  if(jumpi<=jumpj) {
    if(jumpi>=distance){
      return next_i;
    }
    return INF; /// Never
  }
  distance-=jumpi;
  if(distance<=0) {
    return next_i;
  }
 // print_data(i);
 // print_data(j);

  assert(jumpi>jumpj);

  ll gain=jumpi-jumpj;

  ll cnt=0;

  assert(distance>0);

  return next_i+((distance-1)/gain+1)*n;
}

void print_sol() {
  vector<int> solution;
  for (auto &I:rem_inds){
    solution.push_back(frogs[I].index+1);
  }
  sort(solution.begin(),solution.end());
  cout<<(int)solution.size();
  if(!home) cout<<"\n"; else cout<<" : ";
  for (auto &I:solution){
    cout<<I<<" ";
  }
  cout<<"\n";
}

struct Lol {
  ll t;
  int i;
  int j;
};

set<Lol> s;
Lol wws[N];

void update(int i,ll when){
  if(frogs[i].jump==0) return;


  ll pbef=get_position(i,when-1);
  assert(s.count(wws[i]));
  s.erase(wws[i]);

  ii=i;
  ww=when-1;
  iiww=pbef;

  ll pnow=get_position(i,when);

  assert(pnow==rep(pbef+frogs[i].jump));

  vector<int> del;


  auto it=rem_inds.lower_bound(i+1);

  while((int)del.size()<(int)rem_inds.size()-1){
    if(it==rem_inds.end()) it=rem_inds.begin();
    int j=*it;
    assert(i!=j);
    ll pjnow=get_position(j,when);
    assert(pjnow==get_position(j,when-1));
    assert(pbef!=pjnow);
    if(pbef<pnow) {
      if(pbef<pjnow&&pjnow<=pnow){
        frogs[i].jump--;
        frogs[i].x=pnow;
        frogs[i].when_updated=when;
        del.push_back(j);
      }else{
        break;
      }
    }else{
      if(pbef<pjnow||pjnow<=pnow){
        frogs[i].jump--;
        frogs[i].x=pnow;
        frogs[i].when_updated=when;
        del.push_back(j);
      }else{
        break;
      }
    }
    it++;
  }


  for (auto &I : del) {
    rem_inds.erase(I);
  }

  assert(!del.empty());
  if((int)rem_inds.size()>=2){
    auto it=rem_inds.find(i);
    it++;
    if(it==rem_inds.end()) it=rem_inds.begin();
    wws[*it]={when_intersect(i,*it,when+1),i,*it};
    s.insert({when_intersect(i,*it,when+1),i,*it});
  }

  if((int)rem_inds.size()>=2){
    auto it=rem_inds.find(i);

    if(it==rem_inds.begin()) {
      it=rem_inds.end();
      it--;
    }else{
      it--;
    }
    wws[i]={
      when_intersect(*it,i,when+1),
      *it,
      i};
    s.insert(wws[i]);
  }
  if(!del.empty()) {
    if(home){
      cout<<"\t\t\t\tevent at time "<<when<<" : "<<i<<" -> ";
      for(auto&j:del){
        cout<<j<<" ";
      }
      cout<<"\n";
    }
  }
}


bool operator < (Lol a, Lol b){
  if(a.t!=b.t) return a.t<b.t;
  if(a.i!=b.i) return a.i<b.i;
  return a.j<b.j;
}

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif
home=0;

  if(home) {
    freopen("I_am_iron_man","r",stdin);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  time_t bg=clock();
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>frogs[i].x>>frogs[i].jump;
    frogs[i].index=i;

    frogs[i].x--;
    assert(0<=frogs[i].x&&frogs[i].x<m);
    rem_inds.insert(i);
  }

  sort(frogs,frogs+n,cmpFrogX);

  for (int i=0;i<n;i++) {
    where[frogs[i].index]=i;
  }


  ll when=0;
  ll ela=0;


  if(n>1){
    for (int i=0;i<n;i++){
      s.insert({when_intersect(i,(i+1)%n,when),i,(i+1)%n});
      wws[(i+1)%n]={when_intersect(i,(i+1)%n,when),i,(i+1)%n};
   ///   cout<<i<<" "<<(i+1)%n<<" ---> "<<when_intersect(i,(i+1)%n,when)<<"\n";
    }
  }

  while ((int)rem_inds.size()>1&&!s.empty()) {
    auto it=*s.begin();
    s.erase(s.begin());
    if(it.t==INF) continue;
    int i=it.i,j=it.j;
    if(!rem_inds.count(i)) continue;
    if(!rem_inds.count(j)) continue;
    when=it.t;

    int sz1=(int)rem_inds.size();
    if (rem_inds.count(where[when%n])) {
      int i=where[when%n];
      update(i,when);
    }
    int sz2=(int)rem_inds.size();
    assert(sz2<sz1);
    when++;
  }
  print_sol();
}