#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

struct noob
{
    ll tab[5];
    int roz;
};

noob operator+(const noob &a,const noob &b)
{
    noob wyn;
    wyn.roz=a.roz+b.roz;
    FOR(i,5)
    {
        wyn.tab[i]=a.tab[i]+b.tab[(i+(5-a.roz%5))%5];
    }
    return wyn;
}

noob id;


template <typename T, typename A>
struct WDrzewiec 
{
    T klucz;
    A dod;
    A suma;
    WDrzewiec *l;
    WDrzewiec *r;
    int pr;
    WDrzewiec(T _klucz, A _dod)
    {
        klucz=_klucz;
        dod=_dod;
        suma=_dod;
        l=r=NULL;
        pr=rand();
    }
    inline void aktualizuj(WDrzewiec *&t)
    {
        t->suma=id;
        if (t->l!=NULL) t->suma=t->suma+t->l->suma;
        t->suma=t->suma+t->dod;
        if (t->r!=NULL) t->suma=t->suma+t->r->suma;
    }
    inline void rot_lewo(WDrzewiec *&k2)
    {
        WDrzewiec *k1=k2->l;
        k2->l=k1->r;
        k1->r=k2;
        k2=k1;
        aktualizuj(k1->r);
        aktualizuj(k1);
    }
    inline void rot_prawo(WDrzewiec *&k1)
    {
        WDrzewiec *k2=k1->r;
        k1->r=k2->l;
        k2->l=k1;
        k1=k2;
        aktualizuj(k2->l);
        aktualizuj(k2);
    }
    bool usun(T _klucz,WDrzewiec *&t)
    {
        if (t==NULL) return 0;
        if (_klucz< t->klucz) 
        {
            if (usun(_klucz,t->l))
            {
                aktualizuj(t);
                return 1;
            }
            return 0;
        }
        else if (_klucz>t->klucz) 
        {
            if (usun(_klucz,t->r))
            {
                aktualizuj(t);
                return 1;
            }
            return 0;
        }
        else
        {
            ubij(t);
            return 1;
        }
    }
    
    void ubij(WDrzewiec *&t)
    {
        if (t->l==NULL)
        {
            WDrzewiec *temp=t->r;
            delete t;
            t=temp;
            return;
        }
        else if (t->r==NULL)
        {
            WDrzewiec *temp=t->l;
            delete t;
            t=temp;
            return;
        }
        else
        {
            if (t->l->pr<t->r->pr)
            {
                rot_lewo(t);
                ubij(t->r);
            }
            else
            {
                rot_prawo(t);
                ubij(t->l);
            }
            aktualizuj(t);
        }
    }
    
    inline void dodaj(T _klucz,A _dod, WDrzewiec *&t)
    {
        if (t==NULL)
            t=new WDrzewiec(_klucz,_dod);
        else if (_klucz< t->klucz)
        {
            dodaj(_klucz,_dod,t->l);
            if (t->l->pr< t->pr) rot_lewo(t);
            else aktualizuj(t);
        }
        else if (_klucz>t->klucz)
        {
            dodaj(_klucz,_dod,t->r);
            if (t->r->pr< t->pr) rot_prawo(t);
            else aktualizuj(t);
        }
        else
        {
            //duplikat
            t->dod=_dod;
            aktualizuj(t);
        }
    }
    A sumuj(T _mx,WDrzewiec *t) //suma po <=_mx
    {
        A wyn1=id;
        while(t!=NULL)
        {
            
            if (t->klucz<=_mx) 
            {
                if (t->l!=NULL) wyn1=wyn1+t->l->suma;
                if (t->klucz<=_mx) wyn1=wyn1+t->dod;
                t=t->r;
            }
            else
                t=t->l;
        }
        return wyn1;
    }
    void wypisz(WDrzewiec *t)
    {
        if (t==NULL) 
        {
            return;
        }
        cout<<mp(t->klucz,t->pr)<<" "<<t->dod<<" "<<t->suma<<" "<<endl;
        wypisz(t->l);
        wypisz(t->r);
    }
};
template <typename T, typename A>
struct Drzewiec
{
    WDrzewiec<T,A> *korzen;
    Drzewiec()
    {
        korzen=NULL;
    }
    bool usun(T _klucz)
    {
        return korzen->usun(_klucz,korzen);
    }
    void dodaj(T _klucz,A _dod)
    {
        korzen->dodaj(_klucz,_dod,korzen);
    }
    A sumuj(T _mx)
    {
        return korzen->sumuj(_mx,korzen);
    }
    void wypisz()
    {
        korzen->wypisz(korzen);
    }
};





int main()
{
    ios_base::sync_with_stdio(0);
    //srand(time(0));
    id.roz=0;
    FOR(i,5) id.tab[i]=0;
    Drzewiec<int,noob> d;
    int n;string s;
    cin>>n;
    noob tp;
    tp.roz=1;
    FOR(i,5) tp.tab[i]=0;
    FOR(i,n)
    {
        cin>>s;
        int x;
        if (s=="add")
        {
            cin>>x;
            tp.tab[0]=x;
            d.dodaj(x,tp);
        }
        else if (s=="del")
        {
            cin>>x;
            d.usun(x);
        }
        else
        {
            noob w=d.sumuj(2000000000);
            cout<<w.tab[2]<<endl;
        }
    }

    return 0;
}