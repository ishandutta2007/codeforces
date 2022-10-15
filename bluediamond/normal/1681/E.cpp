#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


struct Cell{
  int x,y;
};

Cell read() {
  int x,y;
  cin>>x>>y;
  return {x, y};
}

const int N=(int)2e5+7;
int n;
Cell door[N][2];
int q;
Cell q1[N], q2[N];

int get_dist(Cell a,Cell b) {
  return abs(a.x-b.x) + abs(a.y-b.y);
}

int get_type(Cell a) {
  return max(a.x, a.y);
}

const ll inf=(ll)1e18+7;
ll dist[N][2][2];

struct T {
  bool nmc;
  ll dist[2][2];
};

T operator + (T a,T b) {
  if (a.nmc) return b;
  if (b.nmc) return a;

  T c;
  c.nmc=0;
  for (int i=0;i<2;i++) {
    for (int j=0;j<2;j++) {
      c.dist[i][j]=inf;
    }
  }
  for (int i=0;i<2;i++) {
    for (int j=0;j<2;j++) {
      for (int k=0;k<2;k++) {
        c.dist[i][j]=min(c.dist[i][j],a.dist[i][k]+b.dist[k][j]);
      }
    }
  }
  return c;
}

T t[4*N], nmc;

void build(int v,int tl,int tr) {
  t[v].nmc=0;
  if (tl==tr) {
    for (int i=0;i<2;i++) {
      for (int j=0;j<2;j++) {
        t[v].dist[i][j]=dist[tl][i][j];
      }
    }
    return;
  }
  int tm=(tl+tr)/2;
  build(2*v, tl, tm);
  build(2*v+1, tm+1, tr);
  t[v]=t[2*v]+t[2*v+1];
}

T get(int v,int tl,int tr,int l,int r) {
  if (tr<l||r<tl) return nmc;
  if (l<=tl&&tr<=r) return t[v];
  int tm=(tl+tr)/2;
  return get(2*v,tl,tm,l,r)+get(2*v+1,tm+1,tr,l,r);
}

void build() {
  build(1,1,n-2);
}

T get(int l,int r) {
  assert(1<=l&&l<=r&&r<=n-2);
  return get(1,1,n-2,l,r);
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  nmc.nmc=1;

  cin>>n;
  for (int i=1;i<n;i++) {
    door[i][0]=read();
    door[i][1]=read();

    assert(door[i][0].x==i&&door[i][0].y<=i);
    assert(door[i][1].y==i&&door[i][1].x<=i);
  }

  cin>>q;
  for (int i=1;i<=q;i++) {
    q1[i]=read();
    q2[i]=read();
  }

  for (int i=1;i<=n-2;i++) {
    for (int a=0;a<2;a++) {
      Cell kek=door[i][a];
      if (a==0) kek.x++;
      else kek.y++;
      assert(get_type(kek)==i+1);
      for (int b=0;b<2;b++) {
        dist[i][a][b]=get_dist(kek, door[i+1][b]) + 1;
      }
    }
  }
  if (n>2) {
    build();
  }
/**
  auto it=get(1,2);

  for (int i=0;i<2;i++) {
    for (int j=0;j<2;j++) {
      cout<<"dist["<<i<<"]["<<j<<"] = "<<it.dist[i][j]<<"\n";
    }
  }
  return 0;

**/
/**auto it=get(2,2);
cout<<dist[2][1][0]<<"\n";
cout<<it.dist[1][0]<<"\n";
exit(0);**/
  for (int iq=1;iq<=q;iq++) {
    Cell a=q1[iq];
    Cell b=q2[iq];
    if (get_type(b)<get_type(a)) swap(a,b);
    assert(get_type(a)<=get_type(b));
    if (get_type(a)==get_type(b)) {
      cout<<get_dist(a,b)<<"\n";
      continue;
    }
    if(get_type(a)==get_type(b)-1) {
      ll sol=inf;
      for (int i=0;i<2;i++) {
        Cell kek=door[get_type(a)][i];
        if (i==0) kek.x++;
        else kek.y++;
        assert(get_type(kek)==get_type(a)+1);

        sol=min(sol,get_dist(a,door[get_type(a)][i]) +1LL+ get_dist(kek,b) );
      }
      cout<<sol<<"\n";
      continue;
    }
    assert(n>2);
    ///cout<<"?????? ";
    ///continue;
    T it=get(get_type(a), get_type(b)-2);
    ll sol=inf;
    for (int i=0;i<2;i++) {
      for (int j=0;j<2;j++) {
        Cell kek=door[get_type(b)-1][j];
        if (j==0) kek.x++;
        else kek.y++;
        assert(get_type(kek)==get_type(b));
       /// cout<<" = "<<it.dist[i][j]<<"\n";
       /** if ((i==0&&j==0&&iq==1)||(iq==2)) {
          cout<<i<<" "<<j<<":\n";
          cout<<" = "<<get_dist(a,door[get_type(a)][i])<<"\n";
          cout<<" = 1\n";
          cout<<"it = "<<it.dist[i][j]<<"\n";
          cout<<" = "<<get_dist(b,kek)<<"\n";
          cout<<" = 1\n";
          cout<<"total = "<<get_dist(a,door[get_type(a)][i])+1+it.dist[i][j] + get_dist(b,kek)+1<<"\n";
          cout<<"------------\n";
         /// return 0;
        }**/
        sol=min(sol,get_dist(a,door[get_type(a)][i])+1+it.dist[i][j] + get_dist(b,kek));
      }
    }
    cout<<sol<<"\n";

  }

}