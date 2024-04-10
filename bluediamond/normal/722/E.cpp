#include <bits/stdc++.h>

using namespace std;

bool home = 1;

//#define int ll

typedef long long ll;
typedef long double ld;

const int M=(int)1e9+7;

int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}

int mul(int a,int b){
  return a*(ll)b%M;
}

int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}

int dv(int a,int b){
  return mul(a,pw(b,M-2));
}

void addup(int &a,int b){
  a=add(a,b);
}

void mulup(int &a,int b){
  a=mul(a,b);
}

const int D=200000+7;
int dimx,dimy,n,s,f[D],ifa[D];
map<pair<int,int>,int>mp;

int comb(int n,int k){
  return mul(f[n],mul(ifa[k],ifa[n-k]));
}

int ways(int dx,int dy){
  if(dx<0||dy<0)return 0;
  return comb(dx+dy,dx);
}

int ways(int x1,int y1,int x2,int y2){
  return ways(x2-x1,y2-y1);
}

const int N=2000+7;
const int K=22;
int r[N],c[N],direct[N],cnt[N][K];

bool cmp(pair<int,int>a,pair<int,int>b){
  return a.first+a.second<b.first+b.second;
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

  f[0]=1;
  for (int i=1;i<D;i++)f[i]=mul(f[i-1],i);
  ifa[D-1]=dv(1,f[D-1]);
  for (int i=D-2;i>=0;i--)ifa[i]=mul(ifa[i+1],i+1);

  cin>>dimx>>dimy>>n>>s;
  mp[{1,1}]=0;
  for (int i=1;i<=n;i++){
    int r,c;
    cin>>r>>c;
    mp[{r,c}]=1;
  }
  n=0;
  vector<pair<int,int>>lol;
  for (auto &it:mp)lol.push_back(it.first);
  sort(lol.begin(),lol.end(),cmp);
  for (auto &it:lol){
    n++;
    r[n]=it.first;
    c[n]=it.second;
  }
  /// direct=#incepe din (r,c) si se termina direct la final fara sa treaca prin alt loc

  for (int i=n;i>=1;i--){
    direct[i]=ways(r[i],c[i],dimx,dimy);
    for (int j=i+1;j<=n;j++){
      addup(direct[i],-mul(direct[j],ways(r[i],c[i],r[j],c[j])));
      /// scad daca trec prin mai multe si ultimul prin care trec este j
      /// sincer nu-mi pasa ce se intampla pe drumul i,j
    }
  }

  for (int i=n;i>=1;i--){
    cnt[i][1]=direct[i];
    for (int k=2;k<K;k++){
      ///cnt[i][k]=?
      ///cnt[i][k]=?
      /// cnt[i][k] = total - (cate trec prin >= k) in rest - (cate trec prin < k) in total
      cnt[i][k]=ways(r[i],c[i],dimx,dimy);
      for (int k2=1;k2<k;k2++){
        addup(cnt[i][k],-cnt[i][k2]);
      }
      for (int j=i+1;j<=n;j++){
        addup(cnt[i][k],-mul(cnt[j][k],ways(r[i],c[i],r[j],c[j])));
        /// daca am trecut pe undeva prin mai mult de k atunci j este al k-lea de la coada
      }
    }
  }

  if(mp[{1,1}]==0){
    /// am impartit degeaba
    s*=2;
  }

  ///cout<<s<<"\n";

  int sum=0;
  int total=ways(1,1,dimx,dimy),dif=total;

  for (int k=1;k<K;k++){
    s=(s+1)/2;
   // addup(sum,mul(s,cnt[1][k]));
   int cur=cnt[1][k];
   addup(dif,-cur);
   //cout<<s << " : " <<cur<<"\n";
   addup(sum,mul(s,cur));
  }

  ///cout<<sum<<" vs "<<total<<"\n";
  addup(sum,dif);

  cout<<dv(sum,total)<<"\n";

  return 0;
}