#include <iostream>
#include <cstdio>

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#include <algorithm>
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[250];


bool is_poisson() {
  int sum=0;
  REP(j, 250) sum += a[j];
  double P = sum/250.;
  double dd=0;

  REP(j,250){
    dd+=(P-a[j])*(P-a[j]);
  }
  dd/=250.;
  if(dd<P*2) return true;
  return false;
}
#include <vector>
#include <map>
#include <cassert>
vector<double> ana, anb, xna[50], xnb[50];
int main(){
    DRI(V);
    REP(i,V){
      //fprintf(stderr, "i=%d\n", i);
        int sum=0;
        REP(j,250){
            RI(a[j]);
            sum+=a[j];
        }
        double P = sum / 250.;


        int x=*min_element(a, a+250);
        int y=*max_element(a, a+250);
          map<int, int> d;
          REP(j,250) d[a[j]]++;
          vector<int> v;
          for(auto &&w: d) {
            v.push_back(w.second);
          }
          sort(v.begin(), v.end());
          if(y-x<=20) {

            int freq[30]={};
            REP(j, 250) {
              int d = (a[j]-x);
              freq[d]++;
            }

           
            if(-x>=5) {
              double smax=freq[-x];
              double smin=(freq[0] + freq[y-x]) / 2;
              double s = smax / smin;
            
              if(i<1000) xna[y-x].push_back(s);
              else xnb[y-x].push_back(s);

              if(s>=3) {
               // assert(i<1000);
                puts("poisson");
              }
              else {
              //  assert(i>=1000);
                puts("uniform");
              }
              continue;
            } 


            int fmax=*max_element(freq, freq+y-x+1);
            int fmin=*min_element(freq, freq+y-x+1);
    
          

            
            double thr[30]={
              2, 2, 2, 2, 5, 2,
              5, 2, 5, 2, 5, 
              5, 7, 5, 7.5, 5,
              8, 12, 20, 12, 20, 20,
            };
//            fprintf(stderr, "i=%d y-x+1=%d fmax=%f, fmin=%f, thr*fmin=%f\n", i, y-x+1, (double)fmax, (double)fmin, thr[y-x+1]*fmin);

            

            if(fmax > thr[y-x]*fmin) {
             // assert(i<1000);
              puts("poisson");
            }
            else {
            // assert(i>=1000);
              puts("uniform");
            }



          } else {

            int freq[7] = {};
            REP(j, 250) {
              int d = (a[j]-x)*7/(-2*x);
              if(d<7)
                freq[d]++;
            }
            double fmax=(freq[3]);
            //*max_element(freq, freq+5);
            double fmin=(freq[0]+freq[6]) / 2.0;
             // freq*min_element(freq, freq+5);
            //fprintf(stderr, " i=%d %d %d: %.3f\n",  i, fmax, fmin, fmax/(double)fmin);
              
            if(i<1000) {
              ana.push_back(fmax/(double)fmin);
            } else
              anb.push_back(fmax/(double)fmin);
            
            if(fmax > 2.05*fmin) {
             // assert(i<1000);
              puts("poisson");
            }
            else {
            //  assert(i>=1000);
              puts("uniform");
            }
          }
        


    }
//    fprintf(stderr, "%f %f\n", *min_element(ana.begin(), ana.end()), *max_element(ana.begin(), ana.end()));
//    fprintf(stderr, "%f %f\n", *min_element(anb.begin(), anb.end()), *max_element(anb.begin(), anb.end()));
/*    for(int i=1;i<=25;i++) {
      fprintf(stderr, "xna[%d]\n", i);
      if(SZ(xna[i])) {
    fprintf(stderr, "POISSON: %f %f\n", *min_element(xna[i].begin(), xna[i].end()), *max_element(xna[i].begin(), xna[i].end()));}
    if(SZ(xnb[i])) {
    fprintf(stderr, "UNIFORM: %f %f\n", *min_element(xnb[i].begin(), xnb[i].end()), *max_element(xnb[i].begin(), xnb[i].end()));
      }
    }*/
    return 0;
}