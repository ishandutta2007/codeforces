#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
using namespace std;

vector<int> primes;
vector<bool> temp1;

void sito(int ile) // wrzuca do tablicy primes wszystkie liczby pierwsze <=ile
{
    temp1.resize(ile+1,1);
    temp1[0]=0; temp1[1]=0;
    FOR(i,ile+1)
        if (temp1[i])
        {
            primes.pb(i);
            for(int j=2*i;j<=ile;j+=i)
                temp1[j]=0;
        }
}

int main()
{
    int n;
    sito(5000);
    cin>>n;
    int w=0,k;
    REP(i,1,n)
    {
        k=0;
        FOR(j,primes.sz())
        if (!(i%primes[j]))
            k++;
        if (k==2)
            w++;
        
    }
    cout<<w;
    return 0;
}