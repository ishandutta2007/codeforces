#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <map>
#include <iostream>
#include <set>
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
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
using namespace std;
vector<pair<int,int> > kr;
map<pair<int,int> , int> ind;
int n;
set<int> odc;
int pred[2005];
int w[2005][2005];
int t[2005];

void dodw(int k, int s)
{
    //DBG(k);DBG(s);
    if (s==0) return;
    if (w[k][s]==w[k][s-1]) dodw(k,s-1);
    else {odc.insert(ind[mp(kr[s-1].fi,kr[s-1].se)]);dodw(s-1,s-1);dodw(k,pred[s-1]+1);}
}

void dodt(int k)
{
    if (k==0) return;
    if (t[k]==t[k-1]) dodt(k-1);
    else {odc.insert(ind[mp(kr[k-1].fi,kr[k-1].se)]);dodt(1+pred[k-1]);dodw(k-1,k-1);}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    odc.clear();
    kr.resize(n);
    int a,b;
    FOR(i,n) {cin>>a>>b; kr[i]=mp(a-b,a+b);ind[kr[i]]=i;}
    FOR(i,n) {swap(kr[i].fi,kr[i].se);kr[i].se=-kr[i].se;}sort(kr.begin(),kr.end());FOR(i,n) {swap(kr[i].fi,kr[i].se);kr[i].fi=-kr[i].fi;}
    //FOR(i,n) cout<<kr[i].fi<<" "<<kr[i].se<<endl;
    FOR(i,n+1) FOR(j,n+1) w[i][j]=0;
    FOR(i,n)
    {
        int z=i-1;
        while (z>=0)
        {
            if (kr[z].se<=kr[i].fi) break;
            z--;
        }
        pred[i]=z;
        //cout<<i<<" "<<pred[i]<<endl;
    }
    REP(i,1,n-1) REP(j,1,i)
    {
        int g=j-1;
        if (kr[g].fi>=kr[i].fi) w[i][j]=1+w[g][g]+w[i][pred[g]+1];
        w[i][j]=max(w[i][j],w[i][j-1]);
        //cout<<i<<" "<<j<<" "<<w[i][j]<<endl;
    }
    t[0]=0;
    REP(i,1,n)
    {
        t[i]=max(t[i-1],1+w[i-1][i-1]+t[1+pred[i-1]]);
    }
    cout<<t[n]<<endl;
    dodt(n);
    for(set<int>::iterator it=odc.begin();it!=odc.end();it++) cout<<((*it)+1)<<" ";
    
    return 0;
}