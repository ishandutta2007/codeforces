#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

struct T{
  int l,r,ind;
  ll sol;
};

bool cmp1(T a,T b){
  return a.l>b.l;
}

bool cmp2(T a,T b){
  return a.ind<b.ind;
}

const int stop=(int)2e5+7; /// change later!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const int N=2*stop+77;
vector<int> divi[N];
vector<int> coef[N];
vector<int> val[N];

int get_cnt(int x,int under){
  int sol=0;
  int low=0,high=(int)divi[x].size()-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(divi[x][mid]<=under){
      sol=mid+1;
      low=mid+1;
    }else{
      high=mid-1;
    }
  }
  return sol;
}

ll lcm(ll a, ll b) {
  return a*b/__gcd(a,b);
}

ll lcm(ll a, ll b, ll c) {
  return lcm(a,lcm(b,c));
}

ll get_dumb(ll l, ll r) {
  ll sol=0;
  set<vector<ll>> s;
  for(ll i=l;i<=r;i++) {
    for(ll j=i+1;j<=r;j++) {
      for(ll k=j+1;k<=r;k++){
        sol+=((lcm(i,j,k)>=(i+j+k)));
        bool ok1=((lcm(i,j,k)>=(i+j+k)));
        bool ok2=(lcm(lcm(j,k),i)==lcm(j,k));
        if(lcm(i,j,k)<(i+j+k)){
          assert(ok2);
          assert((lcm(j,k))%(i)==0);
          assert(lcm(j,k)/k<=2);
          assert((2*lcm(i,k))%(j)==0);
        ///  cout<<" = "<<lcm(j,k)/i<<"\n";
          ///assert(lcm(lcm(i,j),k)%lcm(i,j)==0);
          ll x=i,y=j,z=k;



          ///cout<<lcm(lcm(i,k),j)/lcm(i,k)<<"\n";
          assert(lcm(lcm(i,k),j)/lcm(i,k)<=2);
          assert(lcm(lcm(j,k),i)==lcm(j,k));
       ///   cout<<lcm(lcm(j,k),i)/lcm(j,k)<<"\n";
          continue;
         /// s.insert({i/d,j/d,k/d});
          ///cout<<"bad : "<<i/d<<" "<<j/d<<" "<<k/d<<"\n";
        }
      }
    }
  }
  int cnt=0;
  for(auto&v:s){
    cnt++;
   /// cout<<cnt<<" : "<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
  }
  return sol;
}

int last_l=stop;
ll xx[N];
int ptr1[N];
int ptr2[N];
ll aib[N];

void add(int i,ll x){
  while(i<N){
    aib[i]+=x;
    i+=i&(-i);
  }
}

ll get(int i){
  ll sol=0;
  while(i){
    sol+=aib[i];
    i-=i&(-i);
  }
  return sol;
}

ll get_smart(int l, int r) {
  while(last_l>l){
    last_l--;
    for(int k=last_l;k<=stop;k+=last_l){
      while(1){
        assert(ptr1[k]>=0);
        if(last_l==divi[k][ptr1[k]]){
          add(k,val[k][ptr1[k]]);
          xx[k]+=val[k][ptr1[k]];
          break;
        }
        assert(last_l<divi[k][ptr1[k]]);
        ptr1[k]--;
      }
    }
    for(int k=last_l;k<=2*stop;k+=last_l){
      if(k%2==1)continue;
      while(1){
        assert(ptr2[k]>=0);
        if(last_l==divi[k][ptr2[k]]){
          add(k/2,coef[k][ptr2[k]]);
          xx[k/2]+=coef[k][ptr2[k]];
          break;
        }
        assert(last_l<divi[k][ptr2[k]]);
        ptr2[k]--;
      }
    }
  }
  assert(last_l==l);
  set<vector<ll>> s;
  ll bad=get(r)-get(l-1);
  ll len=r-l+1;
  ll total=len*(len-1)*(len-2)/6;
  return total-bad;
}

ll solve(ll l,ll r){
  ll db=get_dumb(l,r);
  ll sm=get_smart(l,r);
  cout<<"dumb  = "<<db<<"\n";
  cout<<"smart = "<<sm<<"\n";
  assert(db==sm);
  return db;
}

signed main()
{
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  for(int i=1;i<N;i++){
    for(int j=i;j<N;j+=i){
      divi[j].push_back(i);
    }
  }
  for(int i=1;i<N;i++){
    ptr1[i]=(int)divi[i].size()-1;
    ptr2[i]=(int)divi[i].size()-1;
  }
  for(int k=1;2*k<N;k++){
    for(auto &i:divi[2*k]){
      ll s=0;
      if(i+1<=k-i)s-=(get_cnt(2*k,k-i)-get_cnt(2*k,i+1-1));
      if(i+1<=k-1)s+=(get_cnt(2*k,k-1)-get_cnt(2*k,i+1-1));
      coef[2*k].push_back(s);
    }
  }
  for (int k=1;2*k<N;k++){
    for (auto &i:divi[k]){
      ll d=0;
      if(i+1<=k-1){
        d=get_cnt(k,k-1)-get_cnt(k,i);
      }
      val[k].push_back(d);
    }
  }
  int t;
  cin>>t;
  vector<T> ofs(t);
  for(int i=0;i<t;i++){
    cin>>ofs[i].l>>ofs[i].r;
    ofs[i].ind=i;
  }
  sort(ofs.begin(),ofs.end(),cmp1);
  for(auto&it:ofs){
    it.sol=get_smart(it.l,it.r);
  }
  sort(ofs.begin(),ofs.end(),cmp2);
  for(auto&it:ofs){
    cout<<it.sol<<"\n";
  }
}