#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
#define F first
#define S second
using namespace std;
const int SIZE = 1111;
int a[SIZE];
void fresh(int &x,int v){x=max(x,v);}
int main(){
    DRII(n,k);
    REP(i,n)RI(a[i]);
    int an=a[0];
    REP(i,n){
        multiset<int>H1;
        multiset<int>H2;
        REP(j,n)H2.insert(a[j]);
        int now=0;
        REPP(j,i,n){
            H1.insert(a[j]);
            H2.erase(H2.find(a[j]));
            now+=a[j];
            multiset<int>::iterator it1=H1.begin();
            multiset<int>::reverse_iterator it2=H2.rbegin();
            int tmp=now;
            an=max(an,tmp); 
            for(int it=0;it<k;it++){
                if(it1==H1.end()||it2==H2.rend())break;
                tmp+=*it2-*it1;
                fresh(an,tmp);
                it1++;
                it2++;
            }
        }
    }
    cout<<an<<endl;
    return 0;
}