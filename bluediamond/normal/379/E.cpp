#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const int N=300+7;
int cnt_rows, width, ys[N][N];

struct T{
  ld a;
  ld b;

  ld eval(ld x) {
    return a*x+b;
  }
};

ld where_meet(T ff, T ss){
  ld a1=ff.a, b1=ff.b;
  ld a2=ss.a, b2=ss.b;
  ld x=(b2-b1)/(a1-a2);
  return x;
}

bool cmp(T ff, T ss){
  if(ff.a==ss.a) return ff.b<ss.b;
  return ff.a<ss.a;
}

ld area[N];

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  cin>>cnt_rows>>width;
  for (int i=1;i<=cnt_rows;i++) {
    for (int j=0;j<=width;j++) {
      cin>>ys[i][j];
    }
  }

  for (int j=0;j+1<=width;j++) {
    vector<T> ant_v;

    for (int pref=1;pref<=cnt_rows;pref++) {
      vector<T> v=ant_v;
      for (int i=pref;i<=pref;i++) {
        ld y0=ys[i][j];
        ld y1=ys[i][j+1];
        /**
        avem : (0, y0) si (1, y1)

        y=a*x+b

        y0=b
        y1=a+b

        **/
        ld b=y0;
        ld a=y1-b;

        /**
        y = a*x+b

        /// la 0 sunt mai mari alea cu b=maxim
        **/

        v.push_back({a, b});
      }

      int pz=(int)v.size()-1;
      while(pz-1>=0&&!cmp(v[pz-1],v[pz])){
        swap(v[pz],v[pz-1]);
        pz--;
      }
      vector<T> stk;

      for (auto &line:v){
        ///cout<<" > "<<line.a<<" "<<line.b<<"\n";
        if(!stk.empty()&&line.a>=stk.back().a&&line.b>=stk.back().b)stk.pop_back();
        while((int)stk.size()>=2&&where_meet(stk[(int)stk.size()-2],line)<where_meet(stk[(int)stk.size()-2],stk[(int)stk.size()-1])){
          stk.pop_back();
        }
        stk.push_back(line);
      }
      v=stk;
      for (int it=0;it<(int)v.size();it++){
        ld start=0;
        ld finish=1;



        if(it-1>=0) start=max((ld)0,where_meet(v[it-1],v[it]));
        if(it+1<(int) v.size()) finish=min((ld)1,where_meet(v[it+1],v[it]));

        if(start>finish) continue;
        ld y_start=v[it].eval(start);
        ld y_finish=v[it].eval(finish);
        area[pref]+=(y_finish+y_start)*(finish-start)*0.5;
      }
      ant_v=v;
    }
  }

  for (int i=1;i<=cnt_rows;i++){
    cout<<fixed<<setprecision(4)<<area[i]-area[i-1]<<"\n";
  }
}